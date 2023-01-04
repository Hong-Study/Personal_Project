using System.Collections;
using System.Collections.Generic;
using System.Transactions;
using UnityEngine;
using UnityEngine.AI;

public class Enemy : MonoBehaviour
{
    public enum Type { A, B, C , D};
    public Type enemy_type;
    public int max_health;
    public int cur_health;
    public Transform target;
    public bool is_chase;
    public BoxCollider melee_area;
    public bool is_attack;
    public GameObject bullet;
    public bool is_dead;

    public int score;
    public GameObject[] coins;


    public Rigidbody rigid;
    public BoxCollider box_collider;
    public MeshRenderer[] meshs;
    public NavMeshAgent nav;
    public Animator anim;
    public Game_Manager manager;

    void Chase_Start()
    {
        is_chase = true;
        anim.SetBool("isWalk", true);
    }
    void Awake()
    {
        rigid = GetComponent<Rigidbody>();
        box_collider = GetComponent<BoxCollider>();
        meshs = GetComponentsInChildren<MeshRenderer>();
        nav = GetComponent<NavMeshAgent>();
        anim = GetComponentInChildren<Animator>();

        if(enemy_type != Type.D)
            Invoke("Chase_Start", 2);
    }

    void Targeting()
    {
        if(is_dead || enemy_type == Type.D)
        {
            return;
        }
        float target_radius = 0;
        float target_range = 0;

        switch (enemy_type)
        {
            case Type.A:
                target_radius = 1.5f;
                target_range = 2f;
                break;
            case Type.B:
                target_radius = 1f;
                target_range = 12f;
                break;
            case Type.C:
                target_radius = 0.5f;
                target_range = 25f;
                break;
            default:
                break;
        }

        RaycastHit[] rayHits = Physics.SphereCastAll(transform.position, target_radius, transform.forward, target_range, LayerMask.GetMask("Player"));
        if(rayHits.Length > 0 && !is_attack)
        {
            StartCoroutine(Attack());
        }
    }

    IEnumerator Attack()
    {
        is_chase = false;
        is_attack = true;
        anim.SetBool("isAttack", true);

        switch (enemy_type)
        {
            case Type.A:
                yield return new WaitForSeconds(0.6f);
                melee_area.enabled = true;

                yield return new WaitForSeconds(1f);
                melee_area.enabled = false;
                break;
            case Type.B:
                yield return new WaitForSeconds(0.1f);
                rigid.AddForce(transform.forward * 20, ForceMode.Impulse);
                melee_area.enabled = true;

                yield return new WaitForSeconds(0.5f);
                rigid.velocity = Vector3.zero;
                melee_area.enabled = false;

                yield return new WaitForSeconds(2f);
                break;
            case Type.C:
                yield return new WaitForSeconds(0.5f);
                GameObject instant_missile = Instantiate(bullet, transform.position + (Vector3.up * 2), transform.rotation);
                Rigidbody rigid_missile = instant_missile.GetComponent<Rigidbody>();
                rigid_missile.velocity = transform.forward * 20;

                yield return new WaitForSeconds(2f);
                break;
            default:
                break;
        }

        

        is_chase = true;
        is_attack = false;
        anim.SetBool("isAttack", false);
    }

    void FixedUpdate()
    {
        Targeting();
        Freeze_Velocity();
    }

    void Freeze_Velocity()
    {
        if (is_chase)
        {
            rigid.velocity = Vector3.zero;
            rigid.angularVelocity = Vector3.zero;
        }
        
    }

    void Update()
    {
        if (nav.enabled)
        {
            nav.SetDestination(target.position);
            nav.isStopped = !is_chase;
        }
        
    }

    

    void OnTriggerEnter(Collider other)
    {
        Vector3 react_vec = (transform.position - other.transform.position).normalized;
        if(other.gameObject.tag == "Melee")
        {
            Weapon weapon = other.GetComponent<Weapon>();
            cur_health -= weapon.damage;
            StartCoroutine(On_Damage(react_vec, false));
        }
        else if(other.tag == "Bullet")
        {
            Bullet bullet = other.GetComponent<Bullet>();
            cur_health -= bullet.damage;
            Destroy(other.gameObject);
            StartCoroutine(On_Damage(react_vec, false));
        }
    }

    public void Hit_By_Grenade(Vector3 explosion_pos)
    {
        cur_health -= 200;
        Vector3 react_vec = transform.position - explosion_pos;
        StartCoroutine(On_Damage(react_vec, true));
    }

    IEnumerator On_Damage(Vector3 react_vec, bool is_grenade)
    {
        
        
        if(cur_health > 0)
        {
            foreach(MeshRenderer mesh in meshs)
            {
                mesh.material.color = Color.red;
            }
            yield return new WaitForSeconds(0.3f);
            foreach (MeshRenderer mesh in meshs)
            {
                mesh.material.color = Color.white;
            }
        }
        else
        {
            gameObject.layer = 13;
            is_dead = true;
            foreach (MeshRenderer mesh in meshs)
            {
                mesh.material.color = Color.gray;
            }
            is_chase = false;
            nav.enabled = false;
            Player player = target.GetComponent<Player>();
            player.score += score;
            int rand_coin = 0;
            Instantiate(coins[rand_coin], transform.position + Vector3.up * 2, Quaternion.identity);
            anim.SetTrigger("doDie");

            switch (enemy_type)
            {
                case Type.A:
                    manager.enemy_cnt_a -= 1;
                    break;
                case Type.B:
                    manager.enemy_cnt_b -= 1;
                    break;
                case Type.C:
                    manager.enemy_cnt_c -= 1;
                    break;
                case Type.D:
                    manager.enemy_cnt_d -= 1;
                    break;
            }

            if (is_grenade)
            {
                react_vec = react_vec.normalized;
                react_vec += Vector3.up * 3;

                rigid.freezeRotation = false;
                rigid.AddForce(react_vec*5, ForceMode.Impulse);
                rigid.AddTorque(react_vec*15, ForceMode.Impulse);
            }
            else
            {
                rigid.AddForce((react_vec * 10), ForceMode.Impulse);
            }
            Destroy(gameObject, 2);
            yield return null;
        }
    }
}

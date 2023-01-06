using System.Collections;
using System.Collections.Generic;
using System.Transactions;
using UnityEngine;
using UnityEngine.AI;

public class Enemy : MonoBehaviour
{
    public int max_health;
    public int cur_health;
    public Transform target;
    public bool is_chase;

    Rigidbody rigid;
    BoxCollider box_collider;
    Material mat;
    NavMeshAgent nav;
    Animator anim;

    void Chase_Start()
    {
        is_chase = true;
        anim.SetBool("isWalk", true);
    }
    void Awake()
    {
        rigid = GetComponent<Rigidbody>();
        box_collider = GetComponent<BoxCollider>();
        mat = GetComponentInChildren<MeshRenderer>().material;
        nav = GetComponent<NavMeshAgent>();
        anim = GetComponentInChildren<Animator>();

        Invoke("Chase_Start", 2);
    }

    void FixedUpdate()
    {
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
        if (is_chase)
        {
            nav.SetDestination(target.position);
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
            mat.color = Color.red;
            yield return new WaitForSeconds(0.3f);
            mat.color = Color.white;
        }
        else
        {
            gameObject.layer = 13;
            mat.color = Color.gray;
            is_chase = false;
            nav.enabled = false;
            anim.SetTrigger("doDie");
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

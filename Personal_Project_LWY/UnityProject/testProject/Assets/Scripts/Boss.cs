using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.AI;

public class Boss : Enemy
{
    public GameObject missile;
    public Transform port_a;
    public Transform port_b;

    Vector3 look_vec;
    Vector3 taunt_vec;
    public bool is_look;
    
    // Start is called before the first frame update
    void Awake()
    {
        rigid = GetComponent<Rigidbody>();
        box_collider = GetComponent<BoxCollider>();
        meshs = GetComponentsInChildren<MeshRenderer>();
        nav = GetComponent<NavMeshAgent>();
        anim = GetComponentInChildren<Animator>();
        nav.isStopped = true;
        StartCoroutine(Think());
    }



    // Update is called once per frame
    void Update()
    {
        if (is_dead)
        {
            StopAllCoroutines();
            return;
        }
        if (is_look)
        {
            float h = Input.GetAxisRaw("Horizontal");
            float v = Input.GetAxisRaw("Vertical");
            look_vec = new Vector3(h, 0, v) * 5f;
            transform.LookAt(target.position + look_vec);
        }
        else
        {
            nav.SetDestination(taunt_vec);
        }
    }

    IEnumerator Think()
    {
        yield return new WaitForSeconds(0.4f);

        int random_action = Random.Range(0, 5);
        switch (random_action)
        {
            case 0:
            case 1:
                StartCoroutine(Missile_Shot());
                break;
            case 2:
            case 3:
                StartCoroutine(Rock_Shot());
                break;
            case 4:
                StartCoroutine(Taunt());
                break;
        }
    }

    IEnumerator Missile_Shot()
    {
        anim.SetTrigger("doShot");
        yield return new WaitForSeconds(0.2f);
        GameObject instant_missile_a = Instantiate(missile, port_a.position, port_a.rotation);
        Boss_Missile boss_missile_a = instant_missile_a.GetComponent<Boss_Missile>();
        boss_missile_a.target = target;

        yield return new WaitForSeconds(0.3f);
        GameObject instant_missile_b = Instantiate(missile, port_b.position, port_b.rotation);
        Boss_Missile boss_missile_b = instant_missile_b.GetComponent<Boss_Missile>();
        boss_missile_b.target = target;
        yield return new WaitForSeconds(2.0f);
        StartCoroutine(Think());
    }

    IEnumerator Rock_Shot()
    {
        is_look = false;
        anim.SetTrigger("doBigShot");
        Instantiate(bullet, transform.position, transform.rotation);
        yield return new WaitForSeconds(3f);
        is_look = true;
        StartCoroutine(Think());
    }

    IEnumerator Taunt()
    {
        taunt_vec = target.position + look_vec;
        is_look = false;
        nav.isStopped = false;
        box_collider.enabled = false;
        anim.SetTrigger("doTaunt");
        yield return new WaitForSeconds(1.5f);
        melee_area.enabled = true;
        yield return new WaitForSeconds(0.5f);
        melee_area.enabled = false;
        yield return new WaitForSeconds(1f);
        is_look = true;
        box_collider.enabled = true;
        nav.isStopped = true;
        StartCoroutine(Think());
    }


}

using System.Collections;
using System.Collections.Generic;
using System.Linq.Expressions;
using UnityEngine;

public class Player : MonoBehaviour
{
    float vAxis;
    float hAxis;
    bool walking;
    bool jump;
    bool dodge;
    bool is_dodge;
    bool is_jumped;
    Vector3 moveTo;
    Vector3 dodgeTo;
    public float speed;
    public float jumpPower;
    Animator anim;
    Rigidbody rigid;
    // Start is called before the first frame update
    void Awake()
    {
        rigid = GetComponent<Rigidbody>();
        anim = GetComponentInChildren<Animator>();
    }

    // Update is called once per frame
    void Update()
    {
        GetInput();
        Move();
        Turn();
        Jump();
        Dodge();
    }

    void GetInput() {
        hAxis = Input.GetAxisRaw("Horizontal");
        vAxis = Input.GetAxisRaw("Vertical");
        walking = Input.GetButton("Walk");
        jump = Input.GetButtonDown("Jump");
        dodge = Input.GetButtonDown("Dodge");
    }

    void Move() {
        moveTo = new Vector3(hAxis, 0, vAxis).normalized;
        if (is_dodge)
        {
            moveTo = dodgeTo;
            transform.position += moveTo * speed * Time.deltaTime;
        }
        else
        {
            transform.position += moveTo * (speed * (walking ? 0.3f : 1.0f)) * Time.deltaTime;
        }
        
        //rigid.velocity = moveTo * (speed * (walking ? 0.3f : 1.0f));
        anim.SetBool("isRun", moveTo != Vector3.zero);
        anim.SetBool("isWalk", walking);
    }

    void Turn()
    {
        transform.LookAt(transform.position + moveTo);
    }

    void Dodge()
    {
        if (dodge && !is_dodge && !is_jumped)
        {
            dodgeTo = moveTo;
            speed *= 2;
            anim.SetTrigger("doDodge");
            is_dodge = true;

            Invoke("DodgeOut", 0.4f);
        }
    }

    void Jump()
    {
        if (jump && !is_jumped && !is_dodge)
        {
            rigid.AddForce(Vector3.up * jumpPower, ForceMode.Impulse);
            is_jumped = true;
            anim.SetBool("isJump", true);
            anim.SetTrigger("doJump");
        }
    }

    void DodgeOut()
    {
        speed *= 0.5f;
        is_dodge = false;
    }

    private void OnCollisionEnter(Collision collision)
    {
        if(collision.gameObject.tag == "Floor")
        {
            anim.SetBool("isJump", false);
            is_jumped = false;
        }
    }
}

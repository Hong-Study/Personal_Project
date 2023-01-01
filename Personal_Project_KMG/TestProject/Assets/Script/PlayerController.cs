using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerController : MonoBehaviour
{
    Animator anim;
    Rigidbody rigid;

    float h, v;

    bool jDown;
    bool isJump = false;
    public float Speed = 10.0f;

    Vector3 moveVec;

    private void Awake()
    {
        rigid = GetComponent<Rigidbody>();
        anim = GetComponentInChildren<Animator>();
    }

    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        GetInput();
        Move();
        Turn();
        Jump();
        
    }

    void GetInput()
    {
        h = Input.GetAxis("Horizontal");
        v = Input.GetAxis("Vertical");
        jDown = Input.GetKeyDown(KeyCode.Space);
    }
    void Move()
    {
        moveVec = new Vector3(h, 0, v).normalized;
        transform.position += moveVec * Speed * Time.deltaTime;
        anim.SetBool("isWalk", moveVec != Vector3.zero);
    }

    void Turn()
    {
        transform.LookAt(transform.position + moveVec); //자연스럽게 회전
    }

    void Jump()
    {
        if(jDown && isJump == false)
        {
            rigid.AddForce(Vector3.up * 5, ForceMode.Impulse);
            anim.SetTrigger("doJump");
            isJump = true;
        }

        else
        {
            return;
        }
    }

    private void OnCollisionEnter(Collision collision)
    {
        if(collision.gameObject.CompareTag("Ground"))
        {
            isJump = false;
        }
    }
}

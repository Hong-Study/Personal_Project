using System.Collections;
using System.Collections.Generic;
using System.Linq.Expressions;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using Unity.VisualScripting;
using UnityEngine;

public class Player : MonoBehaviour
{
    float vAxis;
    float hAxis;

    bool walking;
    bool jump;
    bool dodge;
    bool interact;
    bool swap_1;
    bool swap_2;

    bool is_dodge;
    bool is_jumped;
    bool is_swap;

    public int coin;
    public int maxCoin;

    public int grenade;
    public int maxGrenade;

    Vector3 moveTo;
    Vector3 dodgeTo;
    public float speed;
    public float jumpPower;
    Animator anim;
    Rigidbody rigid;
    GameObject nearObj;
    GameObject equipWeapon;
    public GameObject[] grenades;
    public GameObject[] weapons;
    public bool[] has_weapon;
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
        SwapWeapon();
        Interact();
    }

    void SwapWeapon()
    {
        int weaponIndex = -1;
        if (swap_1) weaponIndex = 0;
        if (swap_2) weaponIndex = 1;
        if((swap_1 || swap_2) && has_weapon[weaponIndex] && !is_jumped && !is_dodge)
        {
            if(equipWeapon == weapons[weaponIndex])
            {
                return;
            }
            if (equipWeapon != null)
            {
                equipWeapon.SetActive(false);
            }
            equipWeapon = weapons[weaponIndex];
            weapons[weaponIndex].SetActive(true);
            anim.SetTrigger("doSwap");
            
        }
    }



    void GetInput() {
        hAxis = Input.GetAxisRaw("Horizontal");
        vAxis = Input.GetAxisRaw("Vertical");
        walking = Input.GetButton("Walk");
        jump = Input.GetButtonDown("Jump");
        dodge = Input.GetButtonDown("Dodge");
        interact = Input.GetButtonDown("Interact");
        swap_1 = Input.GetButtonDown("Swap1");
        swap_2 = Input.GetButtonDown("Swap2");
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

    void Interact()
    {
        if(interact && nearObj != null && !is_jumped && !is_dodge)
        {
            if(nearObj.tag == "Weapon")
            {
                Item item = nearObj.GetComponent<Item>();
                int weaponIndex = item.value;
                has_weapon[weaponIndex] = true;
                Destroy(nearObj);
            }
        }
    }

    void OnCollisionEnter(Collision collision)
    {
        if(collision.gameObject.tag == "Floor")
        {
            anim.SetBool("isJump", false);
            is_jumped = false;
        }
    }

    void OnTriggerEnter(Collider other)
    {
        if(other.tag == "Item")
        {
            Item item = other.GetComponent<Item>();
            switch (item.type)
            {
                case Item.Type.Coin:
                    coin += item.value;
                    if (coin > maxCoin) coin = maxCoin;
                    break;
                case Item.Type.Grenade:
                    grenade += item.value;
                    if (grenade > maxGrenade) grenade = maxGrenade;
                    grenades[grenade-1].SetActive(true);
                    break;
                default:
                    break;
            }
            Destroy(other.gameObject);
        }
    }

    void OnTriggerStay(Collider other)
    {
        if(other.tag == "Weapon")
        {
            nearObj = other.gameObject;
        }
    }

    void OnTriggerExit(Collider other)
    {
        if (other.tag == "Weapon")
        {
            nearObj = null;
        }
    }
}

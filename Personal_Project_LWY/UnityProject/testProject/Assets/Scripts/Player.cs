using System.Collections;
using System.Collections.Generic;
using System.Linq.Expressions;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using Unity.VisualScripting;
using UnityEngine;
using UnityEngine.Android;

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
    bool fire;
    bool reload;
    bool g_down;

    bool is_dodge;
    bool is_jumped;
    bool is_swap;
    bool is_fire;
    bool is_reload;
    bool is_border;
    bool is_damaged;
    bool is_shop;
    bool is_dead;

    float fire_delay;

    public int ammo;

    public int health;
    public int max_health;

    public int coin;
    public int maxCoin;

    public int score;

    public int grenade;
    public int maxGrenade;

    Vector3 moveTo;
    Vector3 dodgeTo;
    public float speed;
    public float jumpPower;
    Animator anim;
    Rigidbody rigid;
    GameObject nearObj;
    public Weapon equipWeapon;
    MeshRenderer[] meshs;
    public GameObject[] grenades;
    public GameObject[] weapons;
    public GameObject throw_grenade;
    public bool[] has_weapon;
    public Camera followCamera;
    public Game_Manager manager;
    public AudioSource jump_sound;


    // Start is called before the first frame update
    void Awake()
    {
        rigid = GetComponent<Rigidbody>();
        anim = GetComponentInChildren<Animator>();
        meshs = GetComponentsInChildren<MeshRenderer>();
        Debug.LogWarning(PlayerPrefs.GetInt("Max_Score"));
        //PlayerPrefs.SetInt("Max_Score", 112500);
    }

    void FreezeRotation()
    {
        rigid.angularVelocity = Vector3.zero;
    }

    void StopToWall()
    {
        //Debug.DrawRay(transform.position, transform.forward * 10, Color.red);
        is_border = Physics.Raycast(transform.position, transform.forward, 1, LayerMask.GetMask("Wall"));
    }

    void FixedUpdate()
    {
        FreezeRotation();
        StopToWall();
    }

    // Update is called once per frame
    void Update()
    {
        GetInput();
        Move();
        Turn();
        Jump();
        Attack();
        Reload();
        Dodge();
        SwapWeapon();
        Interact();
        Grenade();
    }

    void Grenade()
    {
        if (grenade == 0)
        {
            return;
        }
        if (g_down && !is_reload && !is_dodge && !is_jumped && !is_swap && !is_dead)
        {
            Ray ray = followCamera.ScreenPointToRay(Input.mousePosition);
            RaycastHit rayHit;
            if (Physics.Raycast(ray, out rayHit, 100))
            {
                Vector3 nextVec = rayHit.point - transform.position;
                nextVec.y = 5;

                GameObject instant_grenade = Instantiate(throw_grenade, transform.position, transform.rotation);
                Rigidbody rigid_grenade = instant_grenade.GetComponent<Rigidbody>();
                rigid_grenade.AddForce(nextVec * 2, ForceMode.Impulse);
                rigid_grenade.AddTorque(Vector3.back * 5, ForceMode.Impulse);
                grenade -= 1;
                grenades[grenade].SetActive(false);
            }
        }
    }
    void SwapWeapon()
    {
        int weaponIndex = -1;
        if (swap_1) weaponIndex = 0;
        if (swap_2) weaponIndex = 1;
        if ((swap_1 || swap_2) && has_weapon[weaponIndex] && !is_jumped && !is_dodge && !is_dead)
        {
            if (equipWeapon == weapons[weaponIndex].GetComponent<Weapon>())
            {
                return;
            }
            if (equipWeapon != null)
            {
                equipWeapon.gameObject.SetActive(false);
            }
            equipWeapon = weapons[weaponIndex].GetComponent<Weapon>();
            weapons[weaponIndex].gameObject.SetActive(true);
            anim.SetTrigger("doSwap");

        }
    }



    void GetInput() {
        hAxis = Input.GetAxisRaw("Horizontal");
        vAxis = Input.GetAxisRaw("Vertical");
        walking = Input.GetButton("Walk");
        jump = Input.GetButtonDown("Jump");
        fire = Input.GetButton("Fire1");
        dodge = Input.GetButtonDown("Dodge");
        interact = Input.GetButtonDown("Interact");
        swap_1 = Input.GetButtonDown("Swap1");
        swap_2 = Input.GetButtonDown("Swap2");
        reload = Input.GetButtonDown("Reload");
        g_down = Input.GetButtonDown("Fire2");
    }

    void Attack()
    {
        if (equipWeapon == null)
        {
            return;
        }

        fire_delay += Time.deltaTime;
        is_fire = equipWeapon.rate < fire_delay;

        if (fire && is_fire && !is_dodge && !is_swap && !is_shop && !is_dead)
        {
            equipWeapon.Use();
            anim.SetTrigger(equipWeapon.type == Weapon.Type.Melee ? "doSwing" : "doShot");
            fire_delay = 0;
        }
    }

    void Reload()
    {
        if (equipWeapon == null || ammo == 0 || equipWeapon.type == Weapon.Type.Melee)
        {
            return;
        }

        if (reload && !is_dodge && is_fire && !is_jumped && !is_swap && !is_shop && !is_dead && !is_reload && !(equipWeapon.curAmmo == equipWeapon.maxAmmo))
        {
            anim.SetTrigger("doReload");
            is_reload = true;

            Invoke("ReloadOut", 2f);
        }
    }

    void ReloadOut()
    {
        int reAmmo = ammo < equipWeapon.maxAmmo ? ammo : equipWeapon.maxAmmo;
        equipWeapon.curAmmo = reAmmo;
        ammo -= reAmmo;
        is_reload = false;
    }

    void Move() {
        moveTo = new Vector3(hAxis, 0, vAxis).normalized;
        if (is_dodge && !is_dead)
        {
            moveTo = dodgeTo;
            transform.position += moveTo * speed * Time.deltaTime;
        }
        if (!is_border && !is_dead)
        {
            transform.position += moveTo * (speed * (walking ? 0.3f : 1.0f)) * Time.deltaTime;
        }

        //rigid.velocity = moveTo * (speed * (walking ? 0.3f : 1.0f));
        anim.SetBool("isRun", moveTo != Vector3.zero);
        anim.SetBool("isWalk", walking);
    }

    void Turn()
    {
        if (is_dead) return;
        transform.LookAt(transform.position + moveTo);

        if (fire)
        {
            Ray ray = followCamera.ScreenPointToRay(Input.mousePosition);
            RaycastHit rayHit;
            if (Physics.Raycast(ray, out rayHit, 100))
            {
                Vector3 nextVec = rayHit.point - transform.position;
                nextVec.y = 0;
                transform.LookAt(transform.position + nextVec);
            }
        }
    }

    void Dodge()
    {
        if (dodge && !is_dodge && !is_jumped && !is_dead)
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
        if (jump && !is_jumped && !is_dodge && !is_dead)
        {
            rigid.AddForce(Vector3.up * jumpPower, ForceMode.Impulse);
            is_jumped = true;
            anim.SetBool("isJump", true);
            anim.SetTrigger("doJump");
            jump_sound.Play();
        }
    }

    void DodgeOut()
    {
        speed *= 0.5f;
        is_dodge = false;
    }

    void Interact()
    {
        if (interact && nearObj != null && !is_jumped && !is_dodge && !is_dead)
        {
            if (nearObj.tag == "Weapon")
            {
                Item item = nearObj.GetComponent<Item>();
                int weaponIndex = item.value;
                has_weapon[weaponIndex] = true;
                Destroy(nearObj);
            }
            else if (nearObj.tag == "Shop")
            {
                Shop shop = nearObj.GetComponent<Shop>();
                shop.Enter(this);
                is_shop = true;
            }
        }
    }

    void OnCollisionEnter(Collision collision)
    {
        if (collision.gameObject.tag == "Floor")
        {
            anim.SetBool("isJump", false);
            is_jumped = false;
        }
    }

    void OnTriggerEnter(Collider other)
    {
        if (other.tag == "Item")
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
                    grenades[grenade - 1].SetActive(true);
                    break;
                default:
                    break;
            }
            Destroy(other.gameObject);
        }
        else if (other.tag == "Enemy_Bullet")
        {
            if (!is_damaged)
            {
                Bullet enemy_bullet = other.GetComponent<Bullet>();
                health -= enemy_bullet.damage;
                bool is_boss_attack = other.name == "Boss Melee Area";
                StartCoroutine(On_Damage(is_boss_attack));
            }
            if (other.GetComponent<Rigidbody>() != null)
            {
                Destroy(other.gameObject);
            }

        }
    }

    IEnumerator On_Damage(bool is_boss_attack)
    {
        is_damaged = true;
        foreach (MeshRenderer mesh in meshs)
        {
            mesh.material.color = Color.yellow;
        }
        if (is_boss_attack)
        {
            rigid.AddForce(transform.forward * -25, ForceMode.Impulse);
        }

        if (health <= 0 && !is_dead)
        {
            On_Die();
        }

        yield return new WaitForSeconds(1f);
        foreach (MeshRenderer mesh in meshs)
        {
            mesh.material.color = Color.white;
        }
        is_damaged = false;
        if (is_boss_attack)
        {
            rigid.velocity = Vector3.zero;
        }
        
    }

    void On_Die()
    {
        anim.SetTrigger("doDie");
        is_dead = true;
        manager.Game_Over();
    }

    void OnTriggerStay(Collider other)
    {
        if(other.tag == "Weapon" || other.tag == "Shop")
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
        else if(other.tag == "Shop")
        {
            Shop shop = nearObj.GetComponent<Shop>();
            shop.Exit();
            is_shop = false;
            nearObj = null;
        }
    }
}

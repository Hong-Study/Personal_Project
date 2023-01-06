using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Item : MonoBehaviour
{
    public enum Type { Ammo, Coin, Grenade, Heart, Weapon };
    public Type type;
    public int value;
    Rigidbody rigid;
    SphereCollider sph_collider;
    // Start is called before the first frame update
    void Awake()
    {
        rigid = GetComponent<Rigidbody>();
        sph_collider = GetComponent<SphereCollider>();
    }

    // Update is called once per frame
    void Update()
    {
        transform.Rotate(Vector3.up * 20 * Time.deltaTime);
    }

    void OnCollisionEnter(Collision collision)
    {
        if(collision.gameObject.tag == "Floor")
        {
            rigid.isKinematic = true;
            sph_collider.enabled = false;
        }
    }
}

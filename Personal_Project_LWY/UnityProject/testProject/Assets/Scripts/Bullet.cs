using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Bullet : MonoBehaviour
{
    public int damage;
    public bool is_melee;
    public bool is_rock;

    void OnCollisionEnter(Collision collision)
    {
        if(!is_rock && collision.gameObject.tag == "Floor")
        {
            Destroy(gameObject, 3);
        }
        
    }

    void OnTriggerEnter(Collider other)
    {
        if (!is_melee && other.gameObject.tag == "Wall")
        {
            Destroy(gameObject);
        }
    }
}

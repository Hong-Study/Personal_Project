using JetBrains.Rider.Unity.Editor;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Weapon : MonoBehaviour
{
    public enum Type { Melee, Range };
    public Type type;
    public int damage;
    public float rate;
    public BoxCollider meleeArea;
    public TrailRenderer trailEffect;
    public Transform bullet_pos;
    public GameObject bullet;
    public Transform bullet_case_pos;
    public GameObject bullet_case;
    public int maxAmmo;
    public int curAmmo;

    public void Use()
    {
        if(type == Type.Melee)
        {
            StopCoroutine("Swing");
            StartCoroutine("Swing");
        }

        else if(type == Type.Range && curAmmo > 0)
        {
            curAmmo -= 1;
            StopCoroutine("Shot");
            StartCoroutine("Shot");
        }
    }

    IEnumerator Swing()
    {

        yield return new WaitForSeconds(0.1f);
        meleeArea.enabled = true;
        trailEffect.enabled = true;

        yield return new WaitForSeconds(0.3f);
        meleeArea.enabled = false;

        yield return new WaitForSeconds(0.3f);
        trailEffect.enabled = false;
    }

    IEnumerator Shot()
    {
        GameObject instant_bullet = Instantiate(bullet, bullet_pos.position, bullet_pos.rotation);
        Rigidbody bullet_rigid = instant_bullet.GetComponent<Rigidbody>();
        bullet_rigid.velocity = bullet_pos.forward * 500;

        GameObject instant_bullet_case = Instantiate(bullet_case, bullet_case_pos.position, bullet_case_pos.rotation);
        Rigidbody bullet_case_rigid = instant_bullet_case.GetComponent<Rigidbody>();
        Vector3 bullet_case_vec = bullet_case_pos.forward * Random.Range(-3, -2) + Vector3.up * Random.Range(2, 3);
        bullet_case_rigid.AddForce(bullet_case_vec, ForceMode.Impulse);
        bullet_case_rigid.AddTorque(Vector3.up * 10, ForceMode.Impulse);

        yield return null;
        
    }
}

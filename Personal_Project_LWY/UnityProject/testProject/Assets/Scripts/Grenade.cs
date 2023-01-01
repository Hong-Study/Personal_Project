using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Grenade : MonoBehaviour
{
    public GameObject mesh_obj;
    public GameObject effect_obj;
    public Rigidbody rigid;
    // Start is called before the first frame update
    void Start()
    {
        StartCoroutine(Explosion());
    }

    IEnumerator Explosion()
    {
        yield return new WaitForSeconds(2f);
        rigid.velocity = Vector3.zero;
        rigid.angularVelocity = Vector3.zero;
        mesh_obj.SetActive(false);
        effect_obj.SetActive(true);

        RaycastHit[] rayHits = Physics.SphereCastAll(transform.position, 15, Vector3.up, 0f, LayerMask.GetMask("Enemy"));
        foreach(RaycastHit hit_obj in rayHits)
        {
            hit_obj.transform.GetComponent<Enemy>().Hit_By_Grenade(transform.position);
        }
        Destroy(gameObject, 2);
    }
}

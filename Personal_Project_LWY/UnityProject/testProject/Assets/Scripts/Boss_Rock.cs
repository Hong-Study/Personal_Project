using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Boss_Rock : Bullet
{
    Rigidbody rigid;
    float angular_power = 2;
    float scale_Value = 0.1f;
    bool is_shoot;

    void Awake()
    {
        rigid = GetComponent<Rigidbody>();

        StartCoroutine(Gain_Power_Timer());
        StartCoroutine(Gain_Power());
    }



    IEnumerator Gain_Power_Timer()
    {
        yield return new WaitForSeconds(2.2f);
        is_shoot = true;
    }

    IEnumerator Gain_Power()
    {
        while (!is_shoot)
        {
            angular_power += 0.02f;
            scale_Value += 0.005f;
            transform.localScale = Vector3.one * scale_Value;
            rigid.AddTorque(transform.right * angular_power, ForceMode.Acceleration);
            yield return null;
        }
    }
}

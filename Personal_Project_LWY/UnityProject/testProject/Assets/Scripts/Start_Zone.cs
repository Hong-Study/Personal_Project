using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Start_Zone : MonoBehaviour
{
    public Game_Manager manager;

    private void OnTriggerEnter(Collider other)
    {
        if(other.gameObject.tag == "Player")
        {
            manager.Stage_Start();
        }
    }
}

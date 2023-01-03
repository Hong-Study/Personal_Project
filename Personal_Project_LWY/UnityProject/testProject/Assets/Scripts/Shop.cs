using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class Shop : MonoBehaviour
{
    public RectTransform ui_group;
    public Animator anim;
    public GameObject[] item_obj;
    public int[] item_price;
    public Transform[] item_pos;
    public Text talk_text;
    public string[] talk_data;
    Player enter_player;
    // Start is called before the first frame update
    public void Enter(Player player)
    {
        enter_player = player;
        ui_group.anchoredPosition = Vector3.zero;
    }

    // Update is called once per frame
    public void Exit()
    {
        anim.SetTrigger("doHello");
        ui_group.anchoredPosition = Vector3.down * 1000;
    }

    public void Buy(int index)
    {
        int price = item_price[index];
        if(price > enter_player.coin)
        {
            StopCoroutine(Talk());
            StartCoroutine(Talk());
            return;
        }

        enter_player.coin -= price;
        Instantiate(item_obj[index], item_pos[index].position, item_pos[index].rotation);
    }

    public void Buy_Test()
    {
        StopCoroutine(Sold_Out_Talk());
        StartCoroutine(Sold_Out_Talk());
    }

    IEnumerator Talk()
    {
        talk_text.text = talk_data[1];
        yield return new WaitForSeconds(2f);
        talk_text.text = talk_data[0];
    }

    IEnumerator Sold_Out_Talk()
    {
        talk_text.text = "해당 아이템은 품절됐어요..";
        yield return new WaitForSeconds(2f);
        talk_text.text = talk_data[0];
    }
}

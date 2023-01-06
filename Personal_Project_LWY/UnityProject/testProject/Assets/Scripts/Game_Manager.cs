using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.SceneManagement;

public class Game_Manager : MonoBehaviour
{
    public GameObject menu_camera;
    public GameObject game_camera;
    public GameObject item_shop;
    public GameObject weapon_shop;
    public GameObject start_zone;
    public Player player;
    public Boss boss;
    public int stage;
    public float play_time;
    public bool is_battle;
    public int enemy_cnt_a;
    public int enemy_cnt_b;
    public int enemy_cnt_c;
    public int enemy_cnt_d;

    public Transform[] enemy_zone;
    public GameObject[] enemies;
    public List<int> enemy_list;

    public GameObject menu_panel;
    public GameObject game_panel;
    public GameObject over_panel;

    public Text max_score_txt;
    public Text score_txt;
    public Text stage_txt;
    public Text play_time_txt;
    public Text player_health_txt;
    public Text player_coin_txt;
    public Text player_ammo_txt;

    public Image weapon_1_img;
    public Image weapon_2_img;
    public Image weapon_r_img;

    public Text enemy_cnt_a_txt;
    public Text enemy_cnt_b_txt;
    public Text enemy_cnt_c_txt;

    public RectTransform boss_health_group;
    public RectTransform boss_health_bar;

    public Text cur_score_txt;
    public Text best_txt;

    void Awake()
    {
        enemy_list = new List<int>();
        max_score_txt.text = string.Format("{0:n0}", PlayerPrefs.GetInt("Max_Score"));
        if (PlayerPrefs.HasKey("Max_Score"))
        {
            PlayerPrefs.SetInt("Max_Score", 0);
        }
    }

    public void Stage_Start()
    {
        item_shop.SetActive(false);
        weapon_shop.SetActive(false);
        start_zone.SetActive(false);

        foreach (Transform zone in enemy_zone)
        {
            zone.gameObject.SetActive(true);
        }

        is_battle = true;
        StartCoroutine(In_Battle());
    }
    public void Stage_End()
    {
        player.transform.position = new Vector3(-100, 33, 0);
        stage += 1;
        item_shop.SetActive(true);
        weapon_shop.SetActive(true);
        start_zone.SetActive(true);

        foreach (Transform zone in enemy_zone)
        {
            zone.gameObject.SetActive(false);
        }

        is_battle = false;
    }

    IEnumerator In_Battle()
    {
        if (stage % 5 == 0)
        {
            enemy_cnt_d += 1;
            GameObject instant_enemy = Instantiate(enemies[3], enemy_zone[0].position, enemy_zone[0].rotation);
            Enemy enemy = instant_enemy.GetComponent<Enemy>();
            enemy.target = player.transform;
            enemy.manager = this;
            boss = instant_enemy.GetComponent<Boss>();
        }
        else {
            for (int index = 0; index < stage; index++)
            {
                int rand = Random.Range(0, 3);
                enemy_list.Add(rand);

                switch (rand)
                {
                    case 0:
                        enemy_cnt_a += 1;
                        break;
                    case 1:
                        enemy_cnt_b += 1;
                        break;
                    case 2:
                        enemy_cnt_c += 1;
                        break;
                }
            }

            while (enemy_list.Count > 0)
            {
                int rand_zone = Random.Range(0, 4);
                GameObject instant_enemy = Instantiate(enemies[enemy_list[0]], enemy_zone[rand_zone].position, enemy_zone[rand_zone].rotation);
                Enemy enemy = instant_enemy.GetComponent<Enemy>();
                enemy.target = player.transform;
                enemy.manager = this;
                enemy_list.RemoveAt(0);
                yield return new WaitForSeconds(2f);
            }
        }

        while (enemy_cnt_a + enemy_cnt_b + enemy_cnt_c + enemy_cnt_d > 0)
        {
            yield return null;
        }

        yield return new WaitForSeconds(2f);
        boss = null;
        Stage_End();
    }

    public void Game_Start()
    {
        menu_camera.SetActive(false);
        game_camera.SetActive(true);

        menu_panel.SetActive(false);
        game_panel.SetActive(true);

        player.gameObject.SetActive(true);
    }

    public void Game_Over()
    {
        game_panel.SetActive(false);
        over_panel.SetActive(true);
        cur_score_txt.text = score_txt.text;

        int max_score = PlayerPrefs.GetInt("Max_Score");
        if(player.score > max_score)
        {
            best_txt.gameObject.SetActive(true);
            PlayerPrefs.SetInt("Max_Score", player.score);
        }
    }

    public void Restart()
    {
        SceneManager.LoadScene(0);
    }

    void Update()
    {
        if (is_battle)
        {
            play_time += Time.deltaTime;
        }
    }

    void LateUpdate()
    {
        score_txt.text = string.Format("{0:n0}", player.score);
        stage_txt.text = "Stage " + stage;

        int hour = (int)(play_time / 3600);
        int min = (int)((play_time - hour * 3600) / 60);
        int sec = (int)(play_time % 60);
        play_time_txt.text = string.Format("{0:00}", hour) + ":" + string.Format("{0:00}", min) + ":" + string.Format("{0:00}", sec);
        player_health_txt.text = player.health + " / " + player.max_health;
        player_coin_txt.text = string.Format("{0:n0}", player.coin);
        if(player.equipWeapon == null || player.equipWeapon.type == Weapon.Type.Melee)
        {
            player_ammo_txt.text = "- / " + player.ammo;
        }
        else
        {
            player_ammo_txt.text = player.equipWeapon.curAmmo + " / " + player.ammo;
        }
        weapon_1_img.color = new Color(1, 1, 1, player.has_weapon[0] ? 1 : 0);
        weapon_2_img.color = new Color(1, 1, 1, player.has_weapon[1] ? 1 : 0);
        weapon_r_img.color = new Color(1, 1, 1, player.grenade > 0 ? 1 : 0);

        enemy_cnt_a_txt.text = enemy_cnt_a.ToString();
        enemy_cnt_b_txt.text = enemy_cnt_b.ToString();
        enemy_cnt_c_txt.text = enemy_cnt_c.ToString();

        if(boss != null)
        {
            boss_health_group.anchoredPosition = Vector3.down * 29;
            boss_health_bar.localScale = new Vector3((float)boss.cur_health / boss.max_health, 1, 1);
        }
        else
        {
            boss_health_group.anchoredPosition = Vector3.up * 200;
        }
            
    }
}

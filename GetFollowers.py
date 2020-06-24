import instaloader
import time

L = instaloader.Instaloader()

flag = 0

L.login("username", "password")

profile = instaloader.Profile.from_username(L.context, "username")

if flag == 0:
    follow_list = []
    count = 0
    for followers in profile.get_followers():
        follow_list.append(followers.username)
        file = open("followers.txt", "a+")
        file.write(follow_list[count])
        file.write("\n")
        file.close()
        count = count + 1
        flag = 1

time.sleep(60 * 60 * 24)

if flag == 1:
    follow_list = []
    count = 0
    for followers in profile.get_followers():
        follow_list.append(followers.username)
        file = open("follower.txt", "a+")
        file.write(follow_list[count])
        file.write("\n")
        file.close()
        count = count + 1
        flag = 0

time.sleep(60 * 60 * 24)
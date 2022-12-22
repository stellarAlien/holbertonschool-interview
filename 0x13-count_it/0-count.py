#!/usr/bin/python3
"""prints hot articles by keyword from reddit api """
import requests


def count_words(subreddit, word_list, kw_count={}, after=None, word_occ={}):
    """list posts in hot section of a subreddit"""

    if after:
        hot_posts = requests.get('https://reddit.com/r/' + subreddit +
                                 '/hot.json?after=' + after,
                                 headers={"User-Agent": "hot_scraping_app"})
    else:
        hot_posts = requests.get('https://reddit.com/r/' + subreddit +
                                 '/hot.json',
                                 headers={"User-Agent": "hot_scraping_app"})

    # Status 404
    if hot_posts.status_code == 404:
        return

    if kw_count == {}:
        for word in word_list:
            kw_count[word] = 0
            word_occ[word] = word_list.count(word)

    # parse json
    hot_posts_dict = hot_posts.json()
    hot_posts_data = hot_posts_dict['data']
    after = hot_posts_data['after']
    hot_posts_posts = hot_posts_data['children']

    # Post data
    for post in hot_posts_posts:
        post_data = post['data']
        post_title = post_data['title']
        title_words = post_title.split()
        for w in title_words:
            for key in kw_count:
                if w.lower() == key.lower():
                    kw_count[key] += 1

    if after:
        count_words(subreddit, word_list, kw_count, after, word_occ)

    else:
        for k, v in word_occ.items():
            if v > 1:
                kw_count[key] *= v

        sorted_titles = sorted(kw_count.items(), key=lambda x: x[0])
        sorted_res = sorted(sorted_titles, key=lambda x: (-x[1], x[0]))

        for res in sorted_res:
            if res[1] > 0:
                print("{}: {}".format(res[0], res[1]))

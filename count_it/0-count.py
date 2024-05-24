#!/usr/bin/python3

""" Queries the Reddit API, parses the title of all hot articles,
    and prints a sorted count of given keywords
"""

import requests


def count_words(subreddit, word_list, after='', result={}):
    """ Recursive function that queries the Reddit API,
        parses the title of all hot articles,
        and prints a sorted count of given keywords
    """
    if subreddit is None or subreddit == "" or word_list is None:
        return None

    r = requests.get(
        'https://www.reddit.com/r/{}.json'.format(subreddit),
        headers={
            'User-Agent': 'My User Agent 1.0'},
        allow_redirects=False,
        params={
            'limit': 100,
            'after': after})

    if r.status_code != 200:
        return None
    else:
        data = r.json()["data"]
        child_data = data["children"]
        for item in child_data:
            for word in word_list:
                lower = word.lower()
                word_count = item["data"]["title"].lower().split().count(lower)
                if lower in item["data"]["title"].lower():
                    if lower not in result.keys() and word_count > 0:
                        result[lower] = 0 + word_count
                    elif word_count > 0:
                        result[lower] += word_count
        after = data["after"]
        if not result:
            for word in word_list:
                result[word] = 0

    if after is None:
        word_list = [[key, value] for key, value in result.items()]
        word_list = sorted(word_list, key=lambda x: (-x[1], x[0]))
        for word in word_list:
            if word[1]:
                print("{}: {}".format(word[0].lower(), word[1]))
        return None
    else:
        return count_words(subreddit, word_list, after, result)

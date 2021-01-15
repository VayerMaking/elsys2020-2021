import re

def detect_spanish_laughter(string):
    #result = bool(re.search("ja+", string))
    result = bool(re.search("([jJ][aA]){2,}", string))
    return result

#print(detect_spanish_laughter("JaJAjaJa!"))

def valid_phone(string):
    result = bool(re.search("^\+359[0-9]{9}|^359[0-9]{9}|^0+[0-9]{9}", string))
    return result


def get_links(text):
    urls = re.findall('href=[\'"]?([^\'" >]+)', text)
    return urls

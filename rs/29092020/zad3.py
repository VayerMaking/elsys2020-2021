def list_dict(listche):
    my_dict = {}
    my_dict = dict((i, listche.count(i)) for i in listche)
    return my_dict

print(list_dict(["lama", "baba", "kon", "kon"]))

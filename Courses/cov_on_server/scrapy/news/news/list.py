def main():
    file = open("C:\\Users\\LYYRE-OAO\\Desktop\\c.txt", "r+", encoding='utf-8')
    while 1:
        str = file.readline()
        if not str:
            break
        str = str.replace("\"", "")
        str = str.replace("（省/直辖市/特别行政区/自治区）", "")
        str = str.replace("\n", "")
        strlist = str.split("\t")
        str = "{\'name\': \"" + strlist[0] + "\", \'location_id\': " + strlist[1] + "},\n"
        print(str)


if __name__ == '__main__':
    main()
    # print(__name__)

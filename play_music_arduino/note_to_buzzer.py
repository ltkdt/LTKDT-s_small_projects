from pathlib import Path

fileName = "note.txt"

'''
I don't claim copyright to the original source
Check out: https://pianoletternotes.blogspot.com/ . They help piano beginners a lot with simplified version of popular songs.
For this script, I'm playing Bad Apple: https://pianoletternotes.blogspot.com/2018/03/bad-apple-teppei-okada.html
'''

note_dictionary = {
    "a" : "NOTE_A",
    "A" : "NOTE_AS",
    "b" : "NOTE_B",
    "B" : "NOTE_BS",
    "c" : "NOTE_C",
    "C" : "NOTE_CS",
    "d" : "NOTE_D",
    "D" : "NOTE_DS",
    "e" : "NOTE_E",
    "E" : "NOTE_ES",
    "f" : "NOTE_F",
    "F" : "NOTE_FS",
    "g" : "NOTE_G",
    "G" : "NOTE_GS",
}

data = Path(fileName).read_text()

line_count = 0

list_0 = [segment for segment in data.split("\n\n")]

#print(list_0[0].split("\n"))


def handle_one_line(line):
    output = []
    octave = line[0]
    for i in range(2, len(line) - 1 ):
        if line[i] != "-" :
            output.append(note_dictionary[line[i]] + octave)
        else:
            output.append("0")
    return output


def handle_multiple_line(segment):
    lines = segment.split("\n")
    output = handle_one_line(lines[0])

    for line in lines:
        octave = line[0]
        for i in range(2, len(line) - 1):
            if output[i-2] == "0" and line[i] != "-":
                output[i-2] = note_dictionary[line[i]] + octave
    return output

buzzer_final = []

for segment in data.split("\n\n"):
    if segment.count("\n") == 0:
        buzzer_final.extend(handle_one_line(segment))

    else:
        buzzer_final.extend(handle_multiple_line(segment))

print(*buzzer_final, sep=', ')


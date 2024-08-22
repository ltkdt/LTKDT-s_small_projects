from pathlib import Path

fileName = "note.txt"

'''
I don't claim copyright to the original source
Check out: https://pianoletternotes.blogspot.com/ . They help piano beginners a lot with simplified version of popular songs.
For this script, I'm playing Bad Apple: https://pianoletternotes.blogspot.com/2018/03/bad-apple-teppei-okada.html 

Another warning:
Right now, you can use sheets on the website that use two hands. However I discourage you to do so. The reason behind that is that there are many notes that overlap, 
as a result, the music can not be heard clearly or create the intended sound
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

# The below line is meant to check if the formatting from text to different lines work correctly:
# list_0 = [segment for segment in data.split("\n\n")]
 
# Setting two_hand will delete the "RH" and "LH" part
def handle_one_line(line, two_hand = False):
    if two_hand:
        line = line[3:]
    output = []
    octave = line[0]
    for i in range(2, len(line) - 1 ):
        if line[i] != "-" :
            output.append(note_dictionary[line[i]] + octave)
        else:
            output.append("0")
    return output


def handle_multiple_line(segment, two_hand = False):
    lines = segment.split("\n")
    if two_hand:
        lines = [line[3:] for line in lines]
    output = handle_one_line(lines[0])

    for line in lines:
        octave = line[0]
        for i in range(2, len(line) - 1):
            if output[i-2] == "0" and line[i] != "-":
                output[i-2] = note_dictionary[line[i]] + octave
            '''
            If the main melody lies in the lower lines, keep this if clause. 
            Cut this if it is not the case. Normally this is not the case for two-handed tutorial since lines starting with "RH" 
            are for the melody and those with RH are meant for bass
            '''
            # if output[i-2] != "0" and line[i] != "-":                       
            #    output[i-2] = note_dictionary[line[i]] + octave
    return output

buzzer_final = []


for segment in data.split("\n\n"):
    if segment.count("\n") == 0:
        if segment[0][0] == "L" or segment[0] == "R":
            buzzer_final.extend(handle_one_line(segment, True))
        else:
            buzzer_final.extend(handle_one_line(segment))
    else:
        if segment[0][0] == "L" or segment[0] == "R":
            buzzer_final.extend(handle_multiple_line(segment, True))
        else:
            buzzer_final.extend(handle_multiple_line(segment))

print(*buzzer_final, sep=', ')

# If you need to count the number of notes
print(len(buzzer_final))

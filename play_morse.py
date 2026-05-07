import winsound
import time

# Paste a few of your CLEANED codes here
sanskrit_morse = {
    'य': '..-.-',
    'श': '-....-', # Approximating your current output for Yash
}

def play_morse(text):
    for char in text:
        if char in sanskrit_morse:
            code = sanskrit_morse[char]
            print(f"{char}: {code}")
            
            for symbol in code:
                if symbol == '.':
                    winsound.Beep(800, 100)  # Short high beep for Shiva/Dot
                elif symbol == '-':
                    winsound.Beep(800, 300)  # Long high beep for Shakti/Dash
                time.sleep(0.1) # Pause between symbols
            
            time.sleep(0.3) # Pause between letters

# Let's hear your name!
play_morse("यश")
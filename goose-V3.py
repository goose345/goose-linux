import tkinter as tk
import subprocess

def get_xrdb_value(key):
    try:
        result = subprocess.run(
            ["xrdb", "-get", key],
            stdout=subprocess.PIPE,
            stderr=subprocess.PIPE,
            text=True,
            check=True
        )
        return result.stdout.strip() or None
    except subprocess.CalledProcessError:
        return None

def change_monitor(mode):
    match mode:

        case "bath":
            subprocess.run(["xrandr", "--output", "HDMI-1-0", "--auto",  "--output", "eDP", "--off"])


        case "corsham":
            subprocess.run(["xrandr", "--output", "HDMI-1-0", "--mode", "1920x1080", "--rate", "240", "--output", "eDP", "--off"])


        case "laptop": 
            subprocess.run(["xrandr", "--output", "HDMI-1-0", "--off", "--output", "eDP", "--auto"])

    subprocess.run(["feh", "--bg-fill", "/home/goose/Downloads/qq-bg.png"])

def change_theme(theme):
    subprocess.run(["dwm_theme", theme])

def shutdown():
    subprocess.run(["loginctl", "poweroff"])

def reboot():
    subprocess.run(["loginctl", "reboot"])

def loe():
    subprocess.run("echo c | sudo tee /proc/sysrq-trigger", shell=True)


button_color = '#478061'
bg_color = '#000000'

root = tk.Tk()
root.configure(bg=bg_color)
root.title("goose hacker panel")

main_frame = tk.Frame(root, bg=bg_color)
main_frame.grid(row=0, column=0)

# Center the frame in root
root.grid_rowconfigure(0, weight=1)
root.grid_columnconfigure(0, weight=1)

label_title = tk.Label(main_frame, text="goose hacker panel V2", bg=root['bg'], fg=button_color, font=25)

label_display = tk.Label(main_frame, text="display's", bg=root['bg'], fg=button_color, font=25)

frame_monitor = tk.Frame(main_frame, bg=bg_color)

button_laptop = tk.Button(
    frame_monitor,
    text="Laptop Mode",
    bg=bg_color,
    fg=button_color,
    activebackground= button_color,  
    activeforeground=bg_color,    
    font=14,
    width=11,
    height=1,
    highlightbackground=button_color,
    highlightcolor=button_color,
    highlightthickness=1,
    command=lambda: change_monitor("laptop")
)

button_monitor_corsham = tk.Button(
    frame_monitor,
    text="Brie Mode",
    bg=bg_color,
    fg=button_color,
    activebackground= button_color,  
    activeforeground=bg_color,    
    font=14,
    width=11,
    height=1,
    highlightbackground=button_color,
    highlightcolor=button_color,
    highlightthickness=1,
    command=lambda: change_monitor("corsham")
)

button_monitor_bath = tk.Button(
    frame_monitor,
    text="Jinx Mode",
    bg=bg_color,
    fg=button_color,
    activebackground= button_color,  
    activeforeground=bg_color,    
    font=14,
    width=11,
    height=1,
    highlightbackground=button_color,
    highlightcolor=button_color,
    highlightthickness=1,
    command=lambda: change_monitor("bath")
)

button_laptop.grid(row=0, column=1, padx=5, pady=25)
button_monitor_corsham.grid(row=0, column=2, padx=5, pady=25)
button_monitor_bath.grid(row=0, column=3, padx=5, pady=25)

label_themes = tk.Label(main_frame, text="power", bg=root['bg'], fg=button_color, font=14)

frame_themes = tk.Frame(main_frame, bg=bg_color)

button_orange = tk.Button(
    frame_themes,
    text="Orange Mode",
    bg=bg_color,
    fg=button_color,
    activebackground=button_color,  
    activeforeground=bg_color,    
    font=12,
    width=11,
    height=1,
    highlightbackground=button_color,
    highlightcolor=button_color,
    highlightthickness=1,
    command=lambda: change_theme("orange"),
)

button_shutdown = tk.Button(
    frame_themes,
    text="Shutdown mode",
    bg=bg_color,
    fg=button_color,
    activebackground= button_color,  
    activeforeground=bg_color,    
    font=12,
    width=11,
    height=1,
    highlightbackground=button_color,
    highlightcolor=button_color,
    highlightthickness=1,
    command=shutdown
)

button_reboot = tk.Button(
    frame_themes,
    text="Reboot Mode",
    bg=bg_color,
    fg=button_color,
    activebackground=button_color,  
    activeforeground=bg_color,    
    font=12,
    width=11,
    height=1,
    highlightbackground=button_color,
    highlightcolor=button_color,
    highlightthickness=1,
    command=reboot
)

button_orange.grid(row=0, column=1, padx=5, pady=25)
button_shutdown.grid(row=0, column=2, padx=5, pady=25)
button_reboot.grid(row=0, column=3, padx=5, pady=25)

#label_loe = tk.Label(main_frame, text="to be fair", bg=root['bg'], fg=button_color, font=14)

frame_loe = tk.Frame(main_frame, bg=bg_color)

button_quit = tk.Button(
    frame_loe,
    text="Quit",
    bg=bg_color,
    fg=button_color,
    activebackground= button_color,  
    activeforeground=bg_color,    
    font=12,
    width=3,
    height=1,
    highlightbackground=button_color,
    highlightcolor=button_color,
    highlightthickness=1,
    command=root.quit
)

button_terminate = tk.Button(
    frame_loe,
    text="!Terminate Mode!",
    bg=bg_color,
    fg=button_color,
    activebackground= button_color,  
    activeforeground=bg_color,    
    font=12,
    width=14,
    height=1,
    highlightbackground=button_color,
    highlightcolor=button_color,
    highlightthickness=1,
    command=loe,
)

button_quit.grid(row=0, column=1, padx=5, pady=25)
#button_terminate.grid(row=0, column=2, padx=5, pady=25)


label_title.grid(row=0, pady=25)
frame_monitor.grid(row=1)

label_display.grid(row=2, pady=25)
frame_monitor.grid(row=3)

label_themes.grid(row=4, pady=25)
frame_themes.grid(row=5)

#Label_loe.grid(row=6, pady=25)
frame_loe.grid(row=7)

root.mainloop()

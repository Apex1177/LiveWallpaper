#include <iostream>
#include <unistd.h>
#include <thread>
#include <X11/Xlib.h>
#include <err.h>
#include <stdlib.h>
using namespace std;

//todo fullscreen event listener to pause to save resources, URL for background, 
//GUI to select wallpapers and q, transitions between wallpapers when in a q


void playPause(){
    int returnCode = system("dbus-send --type=method_call --dest=org.mpris.MediaPlayer2.vlc /org/mpris/MediaPlayer2 org.mpris.MediaPlayer2.Player.PlayPause");
     if(returnCode == 0){
        cout << "Success play/pause" << endl;
     }else{
        cout << "Error :"
         << returnCode << endl;
     }
}
void eventListener(){
    sleep(5);
    playPause();
    sleep(5);
    playPause();
}
int main(){
/*
    Display *display;
    int width, height, snum;
    snum = DefaultScreen(display);
    width = DisplayWidth(display, snum);
    height = DisplayHeight(display, snum);
    printf("display size is %d x %d\n", width, height);
    //Display *display = XOpenDisplay(NULL);
    //Display *XOpenDisplay(NULL);
*/
    //thread t1(eventListener);


    string vlc = "cvlc";
    string usedwallpaper = " /home/henry/Documents/GitHub/LiveWallpaper/wallpapers";
    string setwallpaper = " --video-wallpaper";
    string aspectratio = " --aspect-ratio= 16:10"; //16:10 is standard for laptop, 1920x1080 is 16:9 standard for desktop
    string autoscale = " --autoscale";
    string autoresize = " --no-qt-video-autoresize";
    string loop = " --loop"; //repeat is current item loop is entire playlist==
    string audio = " --no-audio";
    string embed = " --no-embedded-video";
    string crop = " --crop=16:10"; //todo get monitor size to set crop ratio to work on all displays
    //--key-<function> <code>
    //--key-fullscreen 'Crtl-f'
    string hotkey = " --global-key-play-pause 'Ctrl-q'";
    string fps = " --fps=24";
    string title = " --no-video-title-show";
    string osd = " --no-osd";
    string minview = " --qt-minimal-view";
    string systemtray = " --no-qt-system-tray";
    string videoresize = " --no-qt-video-autoresize";
    string screensaver = " --no-disable-screensaver";
    string videocords = " --video-x=-9999 --video-y=0";
    string quiet = " --quiet";
    string cmdargs = vlc + usedwallpaper + setwallpaper + aspectratio + autoscale + autoresize + loop + audio + embed + crop + hotkey + fps + title + osd + minview + systemtray + videoresize + screensaver + videocords + quiet; 
    const char* cmd = cmdargs.c_str();
    //runs vlc media player via the cmd line for the background
     int returnCode = system(cmd); 
     if(returnCode == 0){
        cout << "Success" << endl;
     }else{
        cout << "Error :"
         << returnCode << endl;
         return 0;
     }

    return 0;
}

#include "GeneratedCommandStreams.h"

namespace GeneratedCommandStreams
{

    //// !!! Insert/edit your animation triggering and playback logic here !!! ////
    /* Some helpful methods:

        BottangoCore::commandStreamProvider.streamIsInProgress()                                        //returns if any animation is currently playing
        BottangoCore::commandStreamProvider.startCommandStream(byte animationID, bool looping)          //starts playing an animation (and stops the current if any)
        BottangoCore::commandStreamProvider.stop()                                                      //stops the current playing animation, if any
    */

    /* Animations key:
        0 - Default Animation
        1 - New Animation
        2 - New Animation
        3 - New Animation
    */

    bool playBegan = false;
    bool playOnStart = false;
    bool loop = false;
    byte startingAnimation = 0;

    // called once per update loop, your logic probably goes here.
    void updatePlayStatus()
    {
        // if haven't started any animations, or if should loop and nothing is playing (IE the last loop ended)
        if (playOnStart && (!playBegan || (loop && !BottangoCore::commandStreamProvider.streamIsInProgress())))
        {
            BottangoCore::commandStreamProvider.startCommandStream(startingAnimation, loop);
            playBegan = true;
        }
    }

    //// ----------------------------------------- /////

    //// GENERATED CODE. You probably don't need to change any of the below ////
    const char SETUP_CHAR_STREAM[] PROGMEM = "rSVI2C,64,0,1000,2000,3000,1000\nrSVI2C,64,1,1000,2000,3000,1000\nrSVI2C,64,2,1000,2000,3000,1000\nrSVI2C,64,3,1000,2000,3000,1000\n";
    const char STREAM_DEFAULTANIMATION_CHAR_STREAM[] PROGMEM = "sC,640,0,533,0,133,0,1000,-133,0\nsC,641,0,533,0,133,0,1000,-133,0\nsC,642,0,533,0,133,0,1000,-133,0\nsC,643,0,533,0,133,0,1000,-133,0\nsC,640,533,500,1000,125,0,0,-125,0\nsC,641,533,500,1000,125,0,0,-125,0\nsC,642,533,500,1000,125,0,0,-125,0\nsC,643,533,500,1000,125,0,0,-125,0\n";
    const char STREAM_DEFAULTANIMATION_CHAR_STREAM_LOOP[] PROGMEM = "";
    const char STREAM_NEWANIMATION_CHAR_STREAM[] PROGMEM = "sC,640,0,433,0,108,0,1000,-108,0\nsC,641,0,433,0,108,0,1000,-108,0\nsC,640,433,567,1000,142,0,0,-142,0\nsC,641,433,567,1000,142,0,0,-142,0\n";
    const char STREAM_NEWANIMATION_CHAR_STREAM_LOOP[] PROGMEM = "";
    const char STREAM_NEWANIMATION1_CHAR_STREAM[] PROGMEM = "sC,642,0,700,0,175,0,1000,-175,0\nsC,643,0,700,0,175,0,1000,-175,0\nsC,642,700,833,1000,208,0,0,-208,0\nsC,643,700,833,1000,208,0,0,-208,0\n";
    const char STREAM_NEWANIMATION1_CHAR_STREAM_LOOP[] PROGMEM = "";
    const char STREAM_NEWANIMATION2_CHAR_STREAM[] PROGMEM = "sC,640,0,600,0,150,0,571,-150,0\nsC,641,0,600,0,150,0,641,-150,0\nsC,642,0,600,0,150,0,626,-150,0\nsC,643,0,600,0,150,0,693,-150,0\nsC,640,600,2367,571,592,0,0,-592,0\nsC,641,600,2367,641,592,0,0,-592,0\nsC,642,600,2367,626,592,0,0,-592,0\nsC,643,600,2367,693,592,0,0,-592,0\n";
    const char STREAM_NEWANIMATION2_CHAR_STREAM_LOOP[] PROGMEM = "";

    CommandStream setupStream = CommandStream(SETUP_CHAR_STREAM, 0);
    CommandStream stream_DefaultAnimation = CommandStream(STREAM_DEFAULTANIMATION_CHAR_STREAM, 1000, STREAM_DEFAULTANIMATION_CHAR_STREAM_LOOP, 0);
    CommandStream stream_NewAnimation = CommandStream(STREAM_NEWANIMATION_CHAR_STREAM, 1000, STREAM_NEWANIMATION_CHAR_STREAM_LOOP, 0);
    CommandStream stream_NewAnimation1 = CommandStream(STREAM_NEWANIMATION1_CHAR_STREAM, 2000, STREAM_NEWANIMATION1_CHAR_STREAM_LOOP, 0);
    CommandStream stream_NewAnimation2 = CommandStream(STREAM_NEWANIMATION2_CHAR_STREAM, 3000, STREAM_NEWANIMATION2_CHAR_STREAM_LOOP, 0);    

    CommandStream *getCommandStream(byte streamID)
    {
        switch (streamID)
        {
        case 0:
            return &stream_DefaultAnimation;
        case 1:
            return &stream_NewAnimation;
        case 2:
            return &stream_NewAnimation1;
        case 3:
            return &stream_NewAnimation2;
        default:
            return NULL;
        }
    }

    CommandStream *getSetupCommandStream()
    {
        return &setupStream;
    }
} // namespace GeneratedCommandStreams

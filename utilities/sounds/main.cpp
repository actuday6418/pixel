
#include <SFML/Audio.hpp>
#include "math.h"

int main()
{
    const int nSamples = 10000; // How many samples do I need for a cycle?
    sf::Int16 samples[nSamples];
    sf::SoundBuffer buffer;
    sf::Sound sound;
    //Fill samples with a pure A tone (440hrz)
    for (int i = 0; i < nSamples ; i++) {
        samples[i] = (10000 * sin(440.0f * (2.0f * 3.1415f) * i / 44100));
    }
    bool ok = buffer.loadFromSamples(samples, nSamples , 1, 44100);
    if (!ok) exit(-1);
    sound.setBuffer(buffer);
    sound.play();
    return 0;
}

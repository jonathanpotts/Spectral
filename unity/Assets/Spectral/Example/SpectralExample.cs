using UnityEngine;
using Spectral;

public class SpectralExample : MonoBehaviour
{
    void Start()
    {
        if (Led.Initialize())
        {
            Led.SetColor(Color.black);
            Led.SetColorForLeds(
                new[] { LedName.W, LedName.A, LedName.S, LedName.D }, 
                Color.magenta
            );
        }
    }

    void OnDestroy()
    {
        Led.Shutdown();
    }
}
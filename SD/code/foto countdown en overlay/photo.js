console.log("herro");

const breedte = 640, hoogte = 480,
    canvas = document.createElement("canvas"),
    ctx = canvas.getContext('2d');

let video = null, isSetup = false;

function Setup() {
    if (!isSetup) {
        canvas.width = breedte;
        canvas.height = hoogte;
        canvas.style.width = `${breedte}px`;
        canvas.style.height = `${hoogte}px`;
        canvas.style.position = 'absolute';
        canvas.style.top = '0';
        canvas.style.left = '0';
        canvas.style.zIndex = '1';

        video = document.getElementById('camera');
        
        // Voeg een event listener toe aan de video voor het starten van het tellenn
        video.addEventListener('click', startAftellen);

        navigator.mediaDevices
            .getUserMedia({ video: true, audio: false })
            .then((stream) => {
                video.srcObject = stream;
                video.play();
            }).catch((err) => {
                console.error(`Fout bij het verkrijgen van de videostream:\n ${err}`);
            });

        isSetup = true;
    }
}

// als je klickt op de video komt de countdown
function startAftellen() {
    let aftellen = 3; //hoeveel seconden hij aftelt
    let aftellenOverlay = document.createElement('div');
    
    // de countdown positie en opmaak
    aftellenOverlay.style.position = 'absolute';
    aftellenOverlay.style.top = '32%';
    aftellenOverlay.style.left = '25%';
    aftellenOverlay.style.transform = 'translate(-50%, -50%)';
    aftellenOverlay.style.fontSize = '100px';
    aftellenOverlay.style.color = 'white';
    document.body.appendChild(aftellenOverlay);

    // interval voor de aftelling
    const aftellenInterval = setInterval(() => {
        if (aftellen > 0) {
            aftellenOverlay.textContent = aftellen;
            aftellen--;
        } else {
            clearInterval(aftellenInterval);
            document.body.removeChild(aftellenOverlay);
            maakFoto();
        }
    }, 1000);
}

// foto maken en deze op een nieuw canvas te laten zien
function maakFoto() {
    const nieuwCanvas = document.createElement('canvas');
    nieuwCanvas.width = breedte;
    nieuwCanvas.height = hoogte;
    nieuwCanvas.style.width = `${breedte}px`;
    nieuwCanvas.style.height = `${hoogte}px`;
    nieuwCanvas.style.position = 'absolute';
    nieuwCanvas.style.top = '0';
    nieuwCanvas.style.left = '1';
    nieuwCanvas.style.zIndex = '1';
    document.body.appendChild(nieuwCanvas);

    const nieuwCtx = nieuwCanvas.getContext('2d');
    nieuwCtx.drawImage(video, 0, 0, breedte, hoogte);

    // verwijder het canvas na 10 seconden
    setTimeout(() => {
        document.body.removeChild(nieuwCanvas);
    }, 10000);
}

Setup();
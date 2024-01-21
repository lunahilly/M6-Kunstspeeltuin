const width = 640, height = 480,
canvas = document.getElementById("canvas");
qr = document.getElementById("qrcode");
ctx = canvas.getContext('2d');

let video = null, isSetup = null;

SetUp();
function SetUp(){
    if(!isSetup){
        canvas.width = width;
        canvas.height = height;
        canvas.style.width = `${width}px`;
        canvas.style.width = `${width}px`;
        canvas.style.backgroundColor = "red";

        

        video = document.getElementById("camera");
        document.addEventListener('click', takePhoto);

        navigator.mediaDevices
        .getUserMedia({video: true, audio: false})
        .then((stream) =>{
            video.srcObject = stream;
            video.play();
        }).catch((err)=>{
            console.error(`Error in obtaining video stream :\n ${err}`);
        });


        isSetup != isSetup;
    }
}

function takePhoto(e){
    e.preventDefault();

    ctx.drawImage(video, 0, 0, width, height);
    let canvasUrl = canvas.toDataURL();
    const createEl = document.createElement("a");
    createEl.href = canvasUrl;

    // naam van de download
    let photo = createEl.download = "photo";
    new QRCode(document.getElementById("qrcode"), a);
    //zorgt dat hij download
    createEl.click();
    createEl.remove();

}


//npx eslint init

//load cells voor stoel op zitten en muziek

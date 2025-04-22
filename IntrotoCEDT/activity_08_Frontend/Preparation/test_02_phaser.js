const config = {
    type: Phaser.AUTO,
    width: 800,
    height: 600,
    scene: {
        preload: preload,
        create: create
    }
};

let game = new Phaser.Game(config);

function preload() {
    // Loading images and other assets in this function
    this.load.image('sky', 'test_02_phaser.jpeg');
}

function create() {
    // Setting up the game world in this function
    this.add.image(400, 300, 'sky');
    this.add.text(400, 300, 'Hello, Jing!', { fontSize: '32px', fill: '#000' });
}

function update() {
    // Code to run on every frame of the game
    // Nothing to run in this example
}
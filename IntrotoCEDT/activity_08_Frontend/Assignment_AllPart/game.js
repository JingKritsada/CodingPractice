class RoomUtil {
  static baseURL = "https://demo.mycourseville.com/act6/";
  static roomApiURL = `${RoomUtil.baseURL}roomapi/`;
  static ROOMSIZE = { w: 800, h: 600 };
  static isReady = false;
  static players = {};

  static getSecret() {
    const urlParams = new URLSearchParams(window.location.search);
    return urlParams.get("secret") || null;
  }
  static getPlayerNumber() {
    const urlParams = new URLSearchParams(window.location.search);
    return urlParams.get("player") || null;
  }

  static getInitAndStartGames(scene, myPlayer) {
    fetch(`${RoomUtil.roomApiURL}getplayerlook.php`, {
      method: "GET",
      headers: {
        "X-Secret": RoomUtil.getSecret(),
      },
    })
      .then((response) => response.json())
      .then((data) => {
        RoomUtil.initAllPlayers(scene, data, myPlayer);

        // ** Solution part 2 -----------------------------------
        RoomUtil.isReady = true;
        // ------------------------------------------------------

        RoomUtil.fetchAllPlayersXY(scene, true);
      })
      .catch((error) => console.error("Error fetching player look data:", error));
  }

  static initAllPlayers(scene, data, myPlayer) {
    Object.keys(data).forEach((key) => {
      const playerData = data[key];
      let player = RoomUtil.players[key];
      if (!player) {
        // ** Solution part 2 -----------------------------------
        if (key === myPlayer.playerNumber) {
          player = myPlayer;
        } else {
          player = new Player(key);
        }

        player.initLookAndVisual(scene, playerData);
        player.setPosition(player.posX, player.posY);
        // ------------------------------------------------------

        RoomUtil.players[key] = player;
      }
    });
  }

  static fetchAllPlayersXY(scene, init = false) {
    // ** Solution part 3 -----------------------------------------------------
    fetch(`${RoomUtil.roomApiURL}getplayerxy.php`, {
      method: "GET",
      headers: {
        "X-Secret": RoomUtil.getSecret(),
      },
    })
      .then((res) => res.json())
      .then((data) => {
        Object.keys(data).forEach((key) => {
          const playerData = data[key];
          let player = RoomUtil.players[key];

          if (player) {
            player.setPosition(playerData.pos_x, playerData.pos_y);
            player.setTarget(playerData.target_x, playerData.target_y);
          }
        });

        if (init) {
          Object.values(RoomUtil.players).forEach((player) => {
            player.updatePlayerInRoom();
          });
        }
      })
      .catch((error) => {
        console.error("Error fetching player XY data:", error);
      });
    // ------------------------------------------------------------------------
  }
}

class Player {
  constructor(playerNumber) {
    this.playerNumber = playerNumber;
    this.look = null;
    this.visual = null;

    // ** Solution part 1 ---------------------------------
    this.posX = Math.random() * RoomUtil.ROOMSIZE.w;
    this.posY = Math.random() * RoomUtil.ROOMSIZE.h;

    this.targetX = this.posX;
    this.targetY = this.posY;
    // ----------------------------------------------------

    // ** Solution part 2 ---------------------------------
    this.speed = 40;
    // ----------------------------------------------------
  }

  getHexFromColorName(colorName) {
    const colorMap = {
      purple: "0x800080",
      blue: "0x0000ff",
      red: "0xff0000",
      orange: "0xffa500",
      yellow: "0xffff00",
      green: "0x008000",
    };

    return colorMap[colorName.toLowerCase()] || 0x000000;
  }

  initLookAndVisual(scene, look) {
    this.look = look;

    if (this.look && (this.look.shape === "circle" || this.look.shape === "square")) {
      // ** Solution part 1 ----------------------------------------------
      if (this.look.shape === "circle") {
        this.visual = scene.add.circle(
          this.posX,
          this.posY,
          5,
          this.getHexFromColorName(this.look.color)
        );
      } else if (this.look.shape === "square") {
        this.visual = scene.add.rectangle(
          this.posX,
          this.posY,
          10,
          10,
          this.getHexFromColorName(this.look.color)
        );
      }
      // -----------------------------------------------------------------
    } else {
      this.visual = scene.add.circle(this.posX, this.posY, 10, 0xff0000);
    }
  }

  setPosition(x, y) {
    this.posX = x;
    this.posY = y;
  }

  setTarget(x, y) {
    this.targetX = x;
    this.targetY = y;
  }

  updatePlayerInRoom() {
    if (this.visual) {
      // ** Solution part 2 ---------------------------------------
      const dx = this.targetX - this.posX;
      const dy = this.targetY - this.posY;
      const distance = Math.sqrt(dx * dx + dy * dy);

      if (distance > this.speed) {
        this.posX += (dx / distance) * this.speed;
        this.posY += (dy / distance) * this.speed;
      } else {
        this.posX = this.targetX;
        this.posY = this.targetY;
      }

      this.visual.setPosition(this.posX, this.posY);
      // ----------------------------------------------------------
    }
  }
}

class MyPlayer extends Player {
  constructor(secret, playerNumber) {
    super(playerNumber);
    this.secret = secret;
  }
  setTarget(x, y) {
    super.setTarget(x, y);
    this.updateMyselfToServer();
  }
  updateMyselfToServer() {
    // ** Solution part 2 ----------------------------------------------------
    const data = new URLSearchParams();
    data.append("pos_x", this.posX);
    data.append("pos_y", this.posY);
    data.append("target_x", this.targetX);
    data.append("target_y", this.targetY);

    fetch(`${RoomUtil.roomApiURL}update.php`, {
      method: "POST",
      headers: {
        "X-Secret": RoomUtil.getSecret(),
        "Content-Type": "application/x-www-form-urlencoded",
      },
      body: data.toString(),
    })
      .then((res) => res.json())
      .then((data) => {
        console.log(data);
      })
      .catch((err) => {
        console.log(err.json());
      });
    // -----------------------------------------------------------------------
  }

  initLookAndVisual(scene, look) {
    // ** Solution part 2 ----------------------------------------------------
    this.look = look;
    if (this.look.shape === "circle" || this.look.shape === "square") {
      if (this.look.shape === "circle") {
        this.visual = scene.add.circle(
          this.posX,
          this.posY,
          5,
          this.getHexFromColorName(this.look.color)
        );

        this.visual.setStrokeStyle(2, 0x000000);
      } else if (this.look.shape === "square") {
        this.visual = scene.add.rectangle(
          this.posX,
          this.posY,
          10,
          10,
          this.getHexFromColorName(this.look.color)
        );

        this.visual.setStrokeStyle(2, 0x000000);
      }
    } else {
      this.visual = scene.add.circle(this.posX, this.posY, 10, 0xff0000);
    }
    // -----------------------------------------------------------------------
  }
}

let game, myPlayer, lastFetchTime, fetchInterval;
let secret = RoomUtil.getSecret();
let playerNumber = RoomUtil.getPlayerNumber();

if (!secret) {
  alert("No secret provided.");
} else if (!playerNumber) {
  alert("No player number provided.");
} else {
  let config = {
    type: Phaser.AUTO,
    width: RoomUtil.ROOMSIZE.w,
    height: RoomUtil.ROOMSIZE.h,
    parent: "gameContainer",
    scene: {
      preload: preload,
      create: create,
      update: update,
    },
  };
  game = new Phaser.Game(config);
  myPlayer = new MyPlayer(RoomUtil.getSecret(), RoomUtil.getPlayerNumber());
  lastFetchTime = 0;
  fetchInterval = 1000;
}

function preload() {
  this.load.image("background", "assets/gridbg.png");
}

function create() {
  this.add.image(
    RoomUtil.ROOMSIZE.w / 2,
    RoomUtil.ROOMSIZE.h / 2,
    "background"
  );

  // ** Solution part 0 : Remove these lines below ------------------------
  // this.add.text(50, 50, `Room Server : ${RoomUtil.roomApiURL}`, {
  //   font: "12px Courier",
  //   fill: "#000000",
  // });
  // -----------------------------------------------------------------------

  this.lastFetchTime = 0;

  this.input.on(
    "pointerdown",
    function (pointer) {
      // ** Solution part 2 ------------------------------------------------
      myPlayer.setTarget(pointer.x, pointer.y);
      // -------------------------------------------------------------------
    },
    this
  );

  RoomUtil.getInitAndStartGames(this, myPlayer);
}

function update(time, delta) {
  if (RoomUtil.isReady) {
    Object.values(RoomUtil.players).forEach((player) => {
      // ** Solution part 2 -------------------------------------
      player.updatePlayerInRoom();
      // --------------------------------------------------------
    });

    // Track the time that has passed since the last fetch
    this.lastFetchTime += delta;

    if (this.lastFetchTime >= fetchInterval) {
      this.lastFetchTime = 0;

      // Fetch updated player positions from the server
      // ** Solution part 3 -------------------------------------
      RoomUtil.fetchAllPlayersXY(this);
      // --------------------------------------------------------
    }
  }
}
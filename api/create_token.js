var crypto = require('crypto');
var co = require('co');

function spawnTokenBuf() {
    return function(callback) {
        crypto.randomBytes(64, callback);
    };
}

co(function* () {
    console.log((yield spawnTokenBuf()).toString('base64'));
});

//node create_token
//OigKDeBKu+v6IcXTvv1svdnOyAClXpam6AwFZ/GVBWHKLreJSv5NuVn/VD/RSlLwZbxggbCZ6L91p5eWZk+GQQ==
//export MY_TOKEN="OigKDeBKu+v6IcXTvv1svdnOyAClXpam6AwFZ/GVBWHKLreJSv5NuVn/VD/RSlLwZbxggbCZ6L91p5eWZk+GQQ=="
//$MY_TOKEN
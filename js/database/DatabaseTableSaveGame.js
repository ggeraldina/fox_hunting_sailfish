function dbGetHandle()
{
    try {
        var db = LocalStorage.openDatabaseSync("databaseFoxHunting", "1.0", "Database for the game FoxHunting", 10000)
    } catch (err) {
        console.log("Error opening database: " + err)
    }
    return db
}

function dbInit(tableName)
{
    var db = dbGetHandle()
    try {
        db.transaction(function (tx) {
            tx.executeSql('CREATE TABLE IF NOT EXISTS ' + tableName
                          + ' (id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL, numberCell INTEGER, fox INTEGER, shot INTEGER)')
        })
    } catch (err) {
        console.log("Error creating table " + tableName + " in database: " + err)
    };
}

//function initTable(db, baseFieldSize){
//    var size = baseFieldSize * baseFieldSize
//    for (var i = 0; i < size; i++) {
//        db.transaction(function (tx) {
//            tx.executeSql('INSERT INTO ' + tableName + ' (numberCell, fox, shot) VALUES(?, ?, ?)', [i, 0, 0])
//        })
//    }
//}

function dbReadAll(tableName)
{
    var db = dbGetHandle()
    db.transaction(function (tx) {
        var results = tx.executeSql('SELECT id, numberCell, fox, shot FROM ' + tableName)
        for (var i = 0; i < results.rows.length; i++) {
            // listModel - it is my stuff (type ListModel)
            listModel.append({
                                 id: results.rows.item(i).id,
                                 numberCell: results.rows.item(i).numberCell,
                                 fox: results.rows.item(i).fox,
                                 shot: results.rows.item(i).shot
                             })
        }
    })
}


function dbInsertRow(tableName, numberCell, fox, shot)
{
    var db = dbGetHandle()
    db.transaction(function (tx) {
        tx.executeSql('INSERT INTO ' + tableName + ' (numberCell, fox, shot) VALUES(?, ?, ?)', [numberCell, fox, shot])
    })
    // listModel - it is my stuff (type ListModel)
//    listModel.clear()
//    dbReadAll()
}

function dbDeleteRow(tableName, id)
{
    var db = dbGetHandle()
    db.transaction(function (tx) {
        tx.executeSql('DELETE FROM ' + tableName + ' WHERE id = ?', [id])
    })
    // listModel - it is my stuff (type ListModel)
    listModel.clear()
    dbReadAll()
}

function dbDeleteAll(tableName)
{
    var db = dbGetHandle()
    db.transaction(function (tx) {
        tx.executeSql('DELETE FROM ' + tableName)
    })
    // listModel - it is my stuff (type ListModel)
    listModel.clear()
}

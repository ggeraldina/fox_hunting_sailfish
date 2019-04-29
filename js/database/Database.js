// general

function dbGetHandle() {
    try {
        var db = LocalStorage.openDatabaseSync("databaseFoxHunting", "1.0", "Database for the game FoxHunting", 10000)
    } catch (err) {
        console.log("Error opening database: " + err)
    }
    return db
}

function dbDeleteRow(tableName, id) {
    var db = dbGetHandle()
    db.transaction(function (tx) {
        tx.executeSql('DELETE FROM ' + tableName + ' WHERE id = ?', [id])
    })
}

function dbDeleteAll(tableName) {
    var db = dbGetHandle()
    db.transaction(function (tx) {
        tx.executeSql('DELETE FROM ' + tableName)
    })
}

// gameStatistics

function dbInitGameStatistics(tableName) {
    var db = dbGetHandle()
    try {
        db.transaction(function (tx) {
            tx.executeSql('CREATE TABLE IF NOT EXISTS ' +
                          tableName +
                          ' (id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL, dataJSON TEXT)')
        })
    } catch (err) {
        console.log("Error creating table " + tableName + " in database: " + err)
    };
}

function dbReadAllGameStatistics(tableName) {
    var db = dbGetHandle()
    db.transaction(function (tx) {
        var results = tx.executeSql('SELECT id, dataJSON FROM ' + tableName)
        for (var i = 0; i < results.rows.length; i++) {
            // listModel - it is my stuff (type ListModel)
            listModel.append({
                                 id: results.rows.item(i).id,
                                 dataJSON: results.rows.item(i).dataJSON
                             })
        }
    })
}

function dbInsertRowGameStatistics(tableName, dataJSON) {
    var db = dbGetHandle()
    db.transaction(function (tx) {
        tx.executeSql('INSERT INTO ' + tableName + ' (dataJSON) VALUES(?)', [dataJSON])
    })
}

//function dbDeleteRowGameStatistics(tableName, id) {
//    dbDeleteRow(tableName, id);
//    // listModel - it is my stuff (type ListModel)
//    listModel.clear()
//    dbReadAllGameStatistics()
//}

function dbDeleteAllGameStatistics(tableName) {
    dbDeleteAll(tableName);
    // listModel - it is my stuff (type ListModel)
    listModel.clear()
}

// locationGameSave

function dbInitLocationGameSave() {
    var db = dbGetHandle()
    try {
        db.transaction(function (tx) {
            tx.executeSql('CREATE TABLE IF NOT EXISTS locationGameSave' +
                          ' (numberCell INTEGER NOT NULL,' +
                          ' fox INTEGER,' +
                          ' shot INTEGER, ' +
                          ' gameId TEXT, ' +
                          ' CONSTRAINT tablePK PRIMARY KEY (numberCell, gameId));')
        })
    } catch (err) {
        console.log("Error creating table locationGameSave in database: " + err)
    };
}

function dbInsertRowLocationGameSave(level, foxes, size, numberCell, fox, shot) {
    var gameId = 'Level' + level + 'Foxes' + foxes + 'Size' +  size
    var db = dbGetHandle()
    db.transaction(function (tx) {
        var results = tx.executeSql('SELECT * FROM locationGameSave WHERE numberCell = ? and gameId = ?;',
                                    [numberCell, gameId])
        if (results.rows.length == 0) {
            tx.executeSql('INSERT INTO locationGameSave (numberCell, fox, shot, gameId) VALUES (?, ?, ?, ?);',
                          [numberCell, fox, shot, gameId])
        } else {
            tx.executeSql('UPDATE locationGameSave SET fox = ?, shot = ? WHERE numberCell = ? and gameId = ?',
                          [fox, shot, numberCell, gameId])
        }
    })

}

function dbReadRowLocationGameSave(level, foxes, size, numberCell) {
    var gameId = 'Level' + level + 'Foxes' + foxes + 'Size' +  size
    var db = dbGetHandle()
    var results = ""
    db.transaction(function (tx) {
        results = tx.executeSql('SELECT fox, shot FROM locationGameSave WHERE numberCell = ? and gameId = ?;',
                                    [numberCell, gameId])

    })
    var obj =  { fox: 0, shot: 0 }
    if (results.rows.length != 0) {
        obj =  { fox: results.rows.item(0).fox, shot: results.rows.item(0).shot }
    }
    return obj
}

function dbDeleteRowLocationGameSave(level, foxes, size, numberCell) {
    var gameId = 'Level' + level + 'Foxes' + foxes + 'Size' +  size
    var db = dbGetHandle()
    db.transaction(function (tx) {
        tx.executeSql('DELETE FROM locationGameSave WHERE numberCell = ? and gameId = ?;',
                      [numberCell, gameId])
    })
}

function dbDeleteGameLocationGameSave(level, foxes, size) {
    var gameId = 'Level' + level + 'Foxes' + foxes + 'Size' +  size
    var db = dbGetHandle()
    db.transaction(function (tx) {
        tx.executeSql('DELETE FROM locationGameSave WHERE gameId = ?;', [gameId])
    })
}

function dbDeleteAllLocationGameSave() {
    dbDeleteAll('locationGameSave');
}

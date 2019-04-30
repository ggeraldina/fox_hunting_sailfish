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
//            tx.executeSql('DROP TABLE IF EXISTS locationGameSave');
            tx.executeSql('CREATE TABLE IF NOT EXISTS locationGameSave' +
                          ' (field TEXT, ' +
                          ' numberCell INTEGER NOT NULL,' +
                          ' fox INTEGER,' +
                          ' shot INTEGER, ' +
                          ' gameId TEXT, ' +
                          ' datetime TEXT, ' +
                          ' CONSTRAINT tablePK PRIMARY KEY (numberCell, field, gameId));')
        })
    } catch (err) {
        console.log("Error creating table locationGameSave in database: " + err)
    };
}

function dbInsertRowLocationGameSave(level, foxes, size, field, numberCell, fox, shot) {
    var gameId = 'Level' + level + 'Foxes' + foxes + 'Size' +  size
    var db = dbGetHandle()
    db.transaction(function (tx) {
        var results = tx.executeSql('SELECT * FROM locationGameSave WHERE field = ? and numberCell = ? and gameId = ?;',
                                    [field, numberCell, gameId])
        if (results.rows.length == 0) {
            tx.executeSql('INSERT INTO locationGameSave (datetime, field, numberCell, fox, shot, gameId) VALUES (datetime("now"), ?, ?, ?, ?, ?);',
                          [field, numberCell, fox, shot, gameId])
        } else {
            tx.executeSql('UPDATE locationGameSave SET shot = ?, datetime = datetime("now") WHERE field = ? and numberCell = ? and gameId = ?',
                          [shot, field, numberCell, gameId])
        }
    })
    console.log("number add " + numberCell + " in " + field)
}

function dbReadRowLocationGameSave(level, foxes, size, field, numberCell) {
    var gameId = 'Level' + level + 'Foxes' + foxes + 'Size' +  size
    var db = dbGetHandle()
    var results = ""
    db.transaction(function (tx) {
        results = tx.executeSql('SELECT fox, shot FROM locationGameSave WHERE field = ? and numberCell = ? and gameId = ?;',
                                    [field, numberCell, gameId])

    })
    var obj =  { fox: 0, shot: 0 }
    if (results.rows.length != 0) {
        obj =  { fox: results.rows.item(0).fox, shot: results.rows.item(0).shot }
    }
    return obj
}

function dbGetFoxesFieldLocationGameSave(level, foxes, size, field) {
    var gameId = 'Level' + level + 'Foxes' + foxes + 'Size' +  size
    var db = dbGetHandle()
    var results = ""
    db.transaction(function (tx) {
        results = tx.executeSql('SELECT numberCell FROM locationGameSave WHERE fox = 1 and field = ? and gameId = ?;',
                                    [field, gameId])
    })
    var obj =  []
    for (var i = 0; i < results.rows.length; i++) {
        obj.push(results.rows.item(i).numberCell)
    }
    return obj
}

function dbPrintLocationGameSave() {
        var db = dbGetHandle()
        var results = ""
        console.log("----------------TABLE------------------")
        db.transaction(function (tx) {
            results = tx.executeSql('SELECT * FROM locationGameSave')
            console.log("i-|field|-|numberCell|-|fox|-|shot|-|gameId|-|datetime|")
            for (var i = 0; i < results.rows.length; i++) {
                console.log(i +
                            " | " + results.rows.item(i).field +
                            " | " + results.rows.item(i).numberCell +
                            " | " + results.rows.item(i).fox +
                            " | " + results.rows.item(i).shot  +
                            " | " + results.rows.item(i).gameId +
                            " | " + results.rows.item(i).datetime )
            }
        })
        console.log("---------------------------------------")
}

function dbDeleteRowLocationGameSave(level, foxes, size, field, numberCell) {
    var gameId = 'Level' + level + 'Foxes' + foxes + 'Size' +  size
    var db = dbGetHandle()
    db.transaction(function (tx) {
        tx.executeSql('DELETE FROM locationGameSave WHERE field = ? and numberCell = ? and gameId = ?;',
                      [field, numberCell, gameId])
    })
    console.log("number remove " + numberCell)
}

function dbDeleteFieldLocationGameSave(level, foxes, size, field) {
    var gameId = 'Level' + level + 'Foxes' + foxes + 'Size' +  size
    var db = dbGetHandle()
    db.transaction(function (tx) {
        tx.executeSql('DELETE FROM locationGameSave WHERE field = ? and gameId = ?;', [field, gameId])
    })
    console.log("delete game in " + field)
}

function dbDeleteAllLocationGameSave() {
    dbDeleteAll('locationGameSave');
}

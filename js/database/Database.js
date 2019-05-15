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

function dbExistsDataTable(tableName) {
    var db = dbGetHandle()
    var results = ""
    db.transaction(function (tx) {
        results = tx.executeSql('SELECT * FROM ' + tableName)
    })
    if (results.rows.length == 0) {
        return false
    }
    return true
}

// for debug

function dbPrintTable(table) {
        var db = dbGetHandle()
        var results = ""
        console.log("-----------TABLE " + table + "-------------")
        db.transaction(function (tx) {
            results = tx.executeSql('SELECT * FROM ' + table)
            for (var i = 0; i < results.rows.length; i++) {
                for(var column in results.rows.item(i)) {
                    console.log(column + ": " + results.rows.item(i)[column])
                }
            }
        })
        console.log("---------------------------------------")
}

// gameStatistics

function dbInitGameStatistics(table) {
    var db = dbGetHandle()
    try {
        db.transaction(function (tx) {
            tx.executeSql('CREATE TABLE IF NOT EXISTS ' +
                          table +
                          ' (id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL, dataJSON TEXT)')
        })
    } catch (err) {
        console.log("Error creating table " + table + " in database: " + err)
    };
}

function dbReadGameStatistics() {
    var db = dbGetHandle()
    db.transaction(function (tx) {
        var results = tx.executeSql('SELECT id, dataJSON FROM gameStatistics')
        for (var i = 0; i < results.rows.length; i++) {
        // listModel - it is my stuff (type ListModel)
            listModel.append({
                                     id: results.rows.item(i).id,
                                     dataJSON: results.rows.item(i).dataJSON
                                 })
        }
    })
}

function dbReadGamePracticeStatistics() {
    var db = dbGetHandle()
    db.transaction(function (tx) {
        var results = tx.executeSql('SELECT id, dataJSON FROM gamePracticeStatistics')
        for (var i = 0; i < results.rows.length; i++) {
            // listModel - it is my stuff (type ListModel)
            listModelPractice.append({
                                 id: "Practice_" + results.rows.item(i).id,
                                 dataJSON: results.rows.item(i).dataJSON
                             })
        }
    })
}

function dbReadGameUserUserStatistics() {
    var db = dbGetHandle()
    db.transaction(function (tx) {
        var results = tx.executeSql('SELECT id, dataJSON FROM gameUserUserStatistics')
        for (var i = 0; i < results.rows.length; i++) {
            // listModel - it is my stuff (type ListModel)
            listModelUserUser.append({
                                 id: "UserUser_" + results.rows.item(i).id,
                                 dataJSON: results.rows.item(i).dataJSON
                             })
        }
    })
}

function dbCountStepsGamePracticeStatistics() {
    var db = dbGetHandle()
    var obj = ""
    db.transaction(function (tx) {
        var results = tx.executeSql('SELECT id, dataJSON FROM gamePracticeStatistics ORDER BY id')
        var lastRow = results.rows.length - 1
        var data = results.rows.item(lastRow).dataJSON
        obj = JSON.parse(data)
    })
    return obj.stepsUser
}

function dbInsertRowGameStatistics(table, dataJSON) {
    var db = dbGetHandle()
    db.transaction(function (tx) {
        tx.executeSql('INSERT INTO ' + table + ' (dataJSON) VALUES(?)', [dataJSON])
    })
}

function dbDeleteAllGameStatistics() {
    dbDeleteAll("gameStatistics");
    dbDeleteAll("gamePracticeStatistics");
    dbDeleteAll("gameUserUserStatistics");
    // listModel - it is my stuff (type ListModel)
    listModel.clear()
    listModelPractice.clear()
    listModelUserUser.clear()
}

// locationGameSave

function dbInitLocationGameSave() {
    var db = dbGetHandle()
    try {
        db.transaction(function (tx) {
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
            tx.executeSql('INSERT INTO locationGameSave (datetime, field, numberCell, fox, shot, gameId)' +
                          ' VALUES (strftime("%Y-%m-%d %H:%M:%f", "now"), ?, ?, ?, ?, ?);',
                          [field, numberCell, fox, shot, gameId])
        } else {
            tx.executeSql('UPDATE locationGameSave SET shot = ?, datetime = strftime("%Y-%m-%d %H:%M:%f", "now")' +
                          ' WHERE field = ? and numberCell = ? and gameId = ?',
                          [shot, field, numberCell, gameId])
        }
    })
}

function dbExistsFieldLocationGameSave(level, foxes, size, field) {
    var gameId = 'Level' + level + 'Foxes' + foxes + 'Size' +  size
    var db = dbGetHandle()
    var results = ""
    db.transaction(function (tx) {
        results = tx.executeSql('SELECT * FROM locationGameSave WHERE field = ? and gameId = ?;',
                                    [field, gameId])
    })
    if (results.rows.length == 0) {
        return false
    } else {
        return true
    }
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

function dbGetStepGameLocationGameSave(level, foxes, size) {
    var gameId = 'Level' + level + 'Foxes' + foxes + 'Size' +  size
    var db = dbGetHandle()
    var results = ""
    db.transaction(function (tx) {
        results = tx.executeSql('SELECT numberCell, field, fox FROM locationGameSave WHERE shot = 1 and gameId = ?' +
                                ' ORDER BY datetime;', [gameId])
    })
    var obj =  []
    for (var i = 0; i < results.rows.length; i++) {
        obj.push( {index: results.rows.item(i).numberCell,
                   field: results.rows.item(i).field,
                   fox: results.rows.item(i).fox} )
    }
    return obj
}

function dbDeleteRowLocationGameSave(level, foxes, size, field, numberCell) {
    var gameId = 'Level' + level + 'Foxes' + foxes + 'Size' +  size
    var db = dbGetHandle()
    db.transaction(function (tx) {
        tx.executeSql('DELETE FROM locationGameSave WHERE field = ? and numberCell = ? and gameId = ?;',
                      [field, numberCell, gameId])
    })
}

function dbDeleteFieldLocationGameSave(level, foxes, size, field) {
    var gameId = 'Level' + level + 'Foxes' + foxes + 'Size' +  size
    var db = dbGetHandle()
    db.transaction(function (tx) {
        tx.executeSql('DELETE FROM locationGameSave WHERE field = ? and gameId = ?;', [field, gameId])
    })
}

function dbDeleteAllLocationGameSave() {
    dbDeleteAll('locationGameSave');
}

// gameStatus

function dbInitGameStatus() {
    var db = dbGetHandle()
    try {
        db.transaction(function (tx) {
//            tx.executeSql('DROP TABLE IF EXISTS gameStatus');
            tx.executeSql('CREATE TABLE IF NOT EXISTS gameStatus' +
                          ' (typeGame TEXT, ' +
                          ' level INTEGER, ' +
                          ' foxes INTEGER, ' +
                          ' size TEXT, ' +
                          ' status TEXT, ' +
                          ' lastWinner TEXT, ' +
                          ' datetime TEXT, ' +
                          ' CONSTRAINT tablePK PRIMARY KEY (typeGame, level, foxes, size));')
        })
    } catch (err) {
        console.log("Error creating table gameStatus in database: " + err)
    };
}

function dbInsertRowGameStatus(typeGame, level, foxes, size, status, lastWinner) {
    // lastWinner = Player1 or Player2;
    var db = dbGetHandle()
    db.transaction(function (tx) {
        var results = tx.executeSql('SELECT * FROM gameStatus WHERE typeGame = ? and level = ? and foxes = ? and size = ?;',
                                    [typeGame, level, foxes, size])
        if (results.rows.length == 0) {
            if (lastWinner === undefined && typeGame == "AI") {
                lastWinner = "Player2"
            } else {
                lastWinner = "Player1"
            }
            tx.executeSql('INSERT INTO gameStatus (datetime, typeGame, level, foxes, size, status, lastWinner)' +
                          ' VALUES (strftime("%Y-%m-%d %H:%M:%f", "now"), ?, ?, ?, ?, ?, ?)',
                          [typeGame, level, foxes, size, status, lastWinner])
        } else {
            if (lastWinner === undefined) {
                tx.executeSql('UPDATE gameStatus SET status = ?, ' +
                              ' datetime = strftime("%Y-%m-%d %H:%M:%f", "now")' +
                              ' WHERE typeGame = ? and level = ? and foxes = ? and size = ?',
                              [status, typeGame, level, foxes, size])
            } else {
                tx.executeSql('UPDATE gameStatus SET status = ?, lastWinner = ?,' +
                              ' datetime = strftime("%Y-%m-%d %H:%M:%f", "now")' +
                              ' WHERE typeGame = ? and level = ? and foxes = ? and size = ?',
                              [status, lastWinner, typeGame, level, foxes, size])
            }
        }
    })
}

function dbGetStatusGameStatus(typeGame, level, foxes, size) {
    var db = dbGetHandle()
    var results = ""
    db.transaction(function (tx) {
        results = tx.executeSql('SELECT status FROM gameStatus WHERE typeGame = ? and level = ? and foxes = ? and size = ?;',
                                    [typeGame, level, foxes, size])
    })
    if (results.rows.length != 0) {
        return results.rows.item(0).status
    }
    return "new"
}

function dbGetLastWinnerGameStatus(typeGame, level, foxes, size) {
    var db = dbGetHandle()
    var results = ""
    db.transaction(function (tx) {
        results = tx.executeSql('SELECT lastWinner FROM gameStatus WHERE typeGame = ? and level = ? and foxes = ? and size = ?;',
                                    [typeGame, level, foxes, size])
    })
    if (results.rows.length != 0) {
        return results.rows.item(0).lastWinner
    }
    return "Player1"
}

function dbDeleteAllGameStatus() {
    dbDeleteAll('gameStatus');
}

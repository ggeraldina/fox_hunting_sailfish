function dbInit(tableName)
{
    var db = LocalStorage.openDatabaseSync("databaseFoxHunting", "1.0", "Database for the game FoxHunting", 10000)
    try {
        db.transaction(function (tx) {
            tx.executeSql('CREATE TABLE IF NOT EXISTS ' + tableName + ' (id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL, dataJSON TEXT)')
        })
    } catch (err) {
        console.log("Error creating table " + tableName + " in database: " + err)
    };
}

function dbGetHandle()
{
    try {
        var db = LocalStorage.openDatabaseSync("databaseFoxHunting", "1.0", "Database for the game FoxHunting", 10000)
    } catch (err) {
        console.log("Error opening database: " + err)
    }
    return db
}

function dbReadAll(tableName)
{
    var db = dbGetHandle()
    db.transaction(function (tx) {
        var results = tx.executeSql('SELECT id, dataJSON FROM ' + tableName)
        for (var i = 0; i < results.rows.length; i++) {
            // listModel - it is my stuff (type ListModel)
            listModel.append({
                                 id: results.rows.item(i).id,
                                 dataJSON: results.rows.item(i).dataJSON
                             })
//            console.log(results.rows.item(i).id)
//            console.log(results.rows.item(i).dataJSON)
        }
    })
}

function dbInsertRow(tableName, dataJSON)
{
    var db = dbGetHandle()
    db.transaction(function (tx) {
        tx.executeSql('INSERT INTO ' + tableName + ' (dataJSON) VALUES(?)', [dataJSON])
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
    dbReadAll()
}


getSmileR :: String -> Handler Html
getSmileR text = defaultLayout $(widgetFile "smile")

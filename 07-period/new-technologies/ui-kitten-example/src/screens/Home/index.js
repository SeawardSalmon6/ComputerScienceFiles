import { Button, Icon, List, ListItem } from "@ui-kitten/components";
import { AppLayout } from "../../components/AppLayout";

import { HomeHeader } from "./components/HomeHeader";
import { useState } from "react";
import { ADD_ITEM_KEY, BASE_ITEMS, getNextKey } from "./constants";
import { AddItemInput } from "./components/InputItem";

export function HomeScreen() {
  const [items, setItems] = useState(BASE_ITEMS);

  return (
    <AppLayout.Base header={<HomeHeader />}>
      <List
        style={{ flexGrow: 0, flexShrink: 1 }}
        data={[{ key: ADD_ITEM_KEY }, ...items]}
        renderItem={({ item }) =>
          ADD_ITEM_KEY === item.key ? (
            <AddItemInput
              onSubmit={(text) =>
                setItems((prev) =>
                  prev.concat({
                    key: getNextKey(prev),
                    title: text,
                    is_favorite: false,
                  })
                )
              }
            />
          ) : (
            <ListItem
              key={item.key}
              title={item.title}
              accessoryRight={
                <Button
                  onPress={() => {
                    setItems((prevItems) =>
                      prevItems.map((prevItem) =>
                        prevItem.key === item.key
                          ? { ...prevItem, is_favorite: !prevItem.is_favorite }
                          : prevItem
                      )
                    );
                  }}
                  appearance="ghost"
                  accessoryRight={
                    <Icon name={item.is_favorite ? "heart" : "heart-outline"} />
                  }
                />
              }
            />
          )
        }
      />
    </AppLayout.Base>
  );
}

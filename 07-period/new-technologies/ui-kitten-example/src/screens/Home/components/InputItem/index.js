import { Button, Icon, Input } from "@ui-kitten/components";
import { useState } from "react";
import { View } from "react-native";
import { styles } from "./styles";

export function AddItemInput({ onSubmit }) {
  const [text, setText] = useState("");

  const onPress = () => {
    onSubmit(text);
    setText("");
  };

  return (
    <View style={styles.container}>
      <Input
        onChangeText={setText}
        onSubmitEditing={onPress}
        placeholder="Insira um novo item"
        style={styles.input}
        value={text}
      />
      <Button
        accessoryRight={<Icon name="plus" />}
        onPress={onPress}
        style={styles.button}
      />
    </View>
  );
}

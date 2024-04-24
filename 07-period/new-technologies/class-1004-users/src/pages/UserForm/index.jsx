import { Text, TextInput, View } from "react-native";
import { styles } from "./styles";
import { useState } from "react";
import { useNavigation, useRoute } from "@react-navigation/native";
import { Button } from "@rneui/themed";
import { useUsersContext } from "../../contexts/UsersContext/useUsersContext";

export function UserForm() {
  const route = useRoute();
  const navigation = useNavigation();
  const [user, setUser] = useState(route.params?.user ?? {});
  const { usersDispatcher } = useUsersContext();

  const getOnChange = (key) => {
    return (value) => {
      setUser((prev) => ({
        ...prev,
        [key]: value,
      }));
    };
  };

  return (
    <View style={styles.form}>
      <Text>Nome</Text>
      <TextInput
        style={styles.input}
        onChangeText={getOnChange("name")}
        placeholder="Insira o nome do usuário"
        value={user.name}
      />
      <Text>E-mail</Text>
      <TextInput
        style={styles.input}
        onChangeText={getOnChange("email")}
        placeholder="Insira o e-mail do usuário"
        value={user.email}
      />
      <Text>Avatar URL</Text>
      <TextInput
        style={styles.input}
        onChangeText={getOnChange("avatarUrl")}
        placeholder="Insira o link do avatar do usuário"
        value={user.avatarUrl}
      />
      <Button
        title="Salvar"
        onPress={() => {
          if (user.id) {
            usersDispatcher({ type: "update", user });
          } else {
            usersDispatcher({ type: "create", user });
          }

          navigation.goBack();
        }}
      />
    </View>
  );
}

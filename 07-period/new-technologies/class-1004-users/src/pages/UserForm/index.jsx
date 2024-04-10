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
  const { setUsers } = useUsersContext();

  return (
    <View style={styles.form}>
      <Text>Nome</Text>
      <TextInput
        style={styles.input}
        onChangeText={(name) => setUser((prev) => ({ ...prev, name }))}
        placeholder="Insira o nome do usuário"
        value={user.name}
      />
      <Text>E-mail</Text>
      <TextInput
        style={styles.input}
        onChangeText={(email) => setUser((prev) => ({ ...prev, email }))}
        placeholder="Insira o e-mail do usuário"
        value={user.email}
      />
      <Text>Avatar URL</Text>
      <TextInput
        style={styles.input}
        onChangeText={(avatarUrl) =>
          setUser((prev) => ({ ...prev, avatarUrl }))
        }
        placeholder="Insira o link do avatar do usuário"
        value={user.avatarUrl}
      />
      <Button
        title="Salvar"
        onPress={() => {
          if (user.id) {
            setUsers((prev) =>
              prev.map((currentUser) =>
                currentUser.id === user.id
                  ? { ...currentUser, ...user }
                  : currentUser
              )
            );
          } else {
            setUsers((prev) => [
              ...prev,
              {
                id: Math.max(...prev.map((u) => u.id)) + 1,
                ...user,
              },
            ]);
          }

          navigation.goBack();
        }}
      />
    </View>
  );
}

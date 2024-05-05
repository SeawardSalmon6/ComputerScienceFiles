import { Text, TextInput, View } from "react-native";
import { styles } from "./styles";
import { useState } from "react";
import { useNavigation, useRoute } from "@react-navigation/native";
import { Button } from "@rneui/themed";
import { useTasksContext } from "../../contexts/TasksContext/useTasksContext";

export function TaskForm() {
  const route = useRoute();
  const navigation = useNavigation();
  const [task, setTask] = useState(route.params?.task ?? {});
  const { tasksDispatcher } = useTasksContext();

  const getOnChange = (key) => {
    return (value) => {
      setTask((prev) => ({
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
        value={task.name}
      />
      <Text>E-mail</Text>
      <TextInput
        style={styles.input}
        onChangeText={getOnChange("email")}
        placeholder="Insira o e-mail do usuário"
        value={task.email}
      />
      <Text>Avatar URL</Text>
      <TextInput
        style={styles.input}
        onChangeText={getOnChange("avatarUrl")}
        placeholder="Insira o link do avatar do usuário"
        value={task.avatarUrl}
      />
      <Button
        title="Salvar"
        onPress={() => {
          if (task.id) {
            tasksDispatcher({ type: "update", user: task });
          } else {
            tasksDispatcher({ type: "create", user: task });
          }

          navigation.goBack();
        }}
      />
    </View>
  );
}

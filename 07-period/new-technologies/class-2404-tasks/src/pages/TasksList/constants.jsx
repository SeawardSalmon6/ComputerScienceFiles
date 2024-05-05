import { Button } from "@rneui/themed";
import { Alert } from "react-native";

const confirmUserDeletion = ({ user, usersDispatcher }) => {
  Alert.alert("Excluir Usuário", "Deseja realmente excluir o usuário?", [
    {
      text: "Sim",
      onPress: () => {
        console.warn(`Usuário *${user.name}* excluído!`);
        usersDispatcher({ type: "delete", user });
      },
    },
    {
      text: "Não",
    },
  ]);
};

export const getUserActions = ({ user, usersDispatcher, navigation }) => {
  return (
    <>
      <Button
        onPress={() => navigation.navigate("user_form", { user })}
        type="clear"
        icon={{ name: "edit", size: 25, color: "orange" }}
      />
      <Button
        onPress={() => confirmUserDeletion({ user, usersDispatcher })}
        type="clear"
        icon={{ name: "delete", size: 25, color: "red" }}
      />
    </>
  );
};

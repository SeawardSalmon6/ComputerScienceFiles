import { FlatList, View } from "react-native";
import { useNavigation } from "@react-navigation/native";
import { Avatar } from "@rneui/base";
import { ListItem } from "@rneui/themed";
import { getUserActions } from "./constants";
import { styles } from "./styles";
import { useTasksContext } from "../../contexts/TasksContext/useTasksContext";

export function TasksList() {
  const { users, tasksDispatcher: usersDispatcher } = useTasksContext();
  const navigation = useNavigation();

  const renderItem = ({ item: user }) => {
    return (
      <ListItem onPress={() => navigation.navigate("user_form")} bottomDivider>
        <Avatar rounded source={{ uri: user.avatarUrl }} />
        <ListItem.Content>
          <ListItem.Title>{user.name}</ListItem.Title>
          <ListItem.Subtitle>{user.email}</ListItem.Subtitle>
        </ListItem.Content>
        {getUserActions({ user, usersDispatcher, navigation })}
      </ListItem>
    );
  };

  return (
    <View style={styles.container}>
      <FlatList
        data={users}
        keyExtractor={(user) => user.id.toString()}
        renderItem={renderItem}
      />
    </View>
  );
}

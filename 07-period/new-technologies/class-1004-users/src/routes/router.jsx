import { NavigationContainer } from "@react-navigation/native";
import { createNativeStackNavigator } from "@react-navigation/native-stack";

import { ScreenA } from "../pages/ScreenA";
import { ScreenB } from "../pages/ScreenB";
import { UsersList } from "../pages/UsersList";
import { UserForm } from "../pages/UserForm";
import { Button, Icon } from "@rneui/themed";

const Stack = createNativeStackNavigator();

export function Routes() {
  return (
    <NavigationContainer>
      <Stack.Navigator
        initialRouteName="users_list"
        screenOptions={screenOptions}
      >
        <Stack.Screen name="screen_a" component={ScreenA} />
        <Stack.Screen name="screen_b" component={ScreenB} />
        <Stack.Screen
          name="users_list"
          component={UsersList}
          options={({ navigation }) => {
            return {
              title: "Lista de Usuários",
              headerRight: () => (
                <Button
                  onPress={() => navigation.navigate("user_form")}
                  type="clear"
                  icon={<Icon name="add" size={25} color="white" />}
                />
              ),
            };
          }}
        />
        <Stack.Screen
          name="user_form"
          component={UserForm}
          options={{
            title: "Formulário de Usuários",
          }}
        />
      </Stack.Navigator>
    </NavigationContainer>
  );
}

const screenOptions = {
  headerStyle: {
    backgroundColor: "#f4511e",
  },
  headerTintColor: "#fff",
  headerTitleStyle: {
    fontWeight: "bold",
  },
};

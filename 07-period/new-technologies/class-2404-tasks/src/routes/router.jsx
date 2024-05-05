import { NavigationContainer } from "@react-navigation/native";
import { createNativeStackNavigator } from "@react-navigation/native-stack";

import { TasksList } from "../pages/TasksList";
import { TaskForm } from "../pages/TaskForm";
import { ImageBackground, Text, View } from "react-native";
import { Button, Icon, Image } from "@rneui/themed";
import { SafeAreaView } from "react-native-safe-area-context";

const Stack = createNativeStackNavigator();

export function Routes() {
  return (
    <NavigationContainer>
      <Stack.Navigator
        initialRouteName="tasks_list"
        screenOptions={screenOptions}
      >
        <Stack.Screen
          name="tasks_list"
          component={TasksList}
          options={({ navigation }) => {
            return {
              headerBackground: () => (
                <SafeAreaView>
                  <Image
                    source={{ uri: "../../assets/images/today.jpg" }}
                    style={
                      {
                        // flex: 1,
                        // justifyContent: "center",
                        // width: "100%",
                        // height: 200,
                      }
                    }
                    resizeMode="cover"
                  >
                    <Text>Here</Text>
                  </Image>
                </SafeAreaView>
              ),
              // title: "Lista de Tarefas",
              // headerRight: () => (
              //   <Button
              //     onPress={() => navigation.navigate("task_form")}
              //     type="clear"
              //     icon={<Icon name="add" size={25} color="white" />}
              //   />
              // ),
            };
          }}
        />
        <Stack.Screen
          name="task_form"
          component={TaskForm}
          options={{
            title: "Formulário de Tarefa",
          }}
        />
      </Stack.Navigator>
    </NavigationContainer>
  );
}

const screenOptions = {
  // headerStyle: {
  //   backgroundColor: "#f4511e",
  // },
  // headerTintColor: "#fff",
  // headerTitleStyle: {
  //   fontWeight: "bold",
  // },
};

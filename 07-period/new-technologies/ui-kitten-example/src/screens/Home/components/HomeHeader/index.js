import { Avatar, Icon, Text, TopNavigationAction } from "@ui-kitten/components";
import { AppLayout } from "../../../../components/AppLayout";
import { View } from "react-native";
import { useState } from "react";
import { styles } from "./styles";

export function HomeHeader() {
  const [eyesClosed, setEyesClosed] = useState(false);

  return (
    <AppLayout.Header
      accessoryLeft={
        <Avatar
          source={require("../../../../../assets/avatar.png")}
          style={styles.avatar}
        />
      }
      accessoryRight={
        <View style={styles.buttonsContainer}>
          <TopNavigationAction
            style={styles.button}
            onPress={() => setEyesClosed((prev) => !prev)}
            icon={
              <Icon
                name={!eyesClosed ? "eye-outline" : "eye-off-outline"}
                {...styles.icon}
              />
            }
          />
          <TopNavigationAction
            style={styles.button}
            icon={<Icon name="question-mark-circle-outline" {...styles.icon} />}
          />
          <TopNavigationAction
            style={styles.button}
            icon={<Icon name="share-outline" {...styles.icon} />}
          />
        </View>
      }
      containerStyle={styles.header}
    >
      <View style={styles.titleContainer}>
        <Text style={styles.title}>Olá, Kitten</Text>
      </View>
    </AppLayout.Header>
  );
}

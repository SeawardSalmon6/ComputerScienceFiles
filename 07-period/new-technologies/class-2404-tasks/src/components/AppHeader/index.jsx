import { Button, Text, View } from "react-native";
import { useNavigation } from "@react-navigation/native";
import { styles } from "./styles";

export function AppHeader({ title, redirectTo }) {
  const navigation = useNavigation();

  return (
    <View style={styles.container}>
      <Text style={styles.text}>{title}</Text>
      {redirectTo && (
        <Button
          title={`Go to ${redirectTo.title}`}
          onPress={() => {
            navigation.navigate(redirectTo.path);
          }}
        />
      )}
    </View>
  );
}

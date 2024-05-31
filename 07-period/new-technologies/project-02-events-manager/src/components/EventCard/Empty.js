import { Text, View } from "react-native";
import { styles } from "./styles";

export function Empty({ text = "Não há nada por aqui" }) {
  return (
    <View style={[styles.container, styles.emptyContainer]}>
      <Text style={styles.emptyText}>{text}</Text>
    </View>
  );
}

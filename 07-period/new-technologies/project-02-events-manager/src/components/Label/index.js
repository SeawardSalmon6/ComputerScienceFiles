import { Text } from "react-native";
import { styles } from "./styles";

export function Label({ label, required }) {
  return (
    <Text style={styles.label}>
      {label}
      {required && <Text style={styles.required}> *</Text>}
    </Text>
  );
}

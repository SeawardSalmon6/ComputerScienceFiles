import styles from "@/components/Form/styles";
import { View } from "react-native";

export function Form({ children }) {
  return <View style={styles.container}>{children}</View>;
}

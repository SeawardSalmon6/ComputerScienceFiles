import { View } from "react-native";
import { styles } from "./styles";

export function Content({ style, children }) {
  return <View style={[styles.contentContainer, style]}>{children}</View>;
}

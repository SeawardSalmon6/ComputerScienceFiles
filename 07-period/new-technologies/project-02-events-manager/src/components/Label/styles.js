import { StyleSheet } from "react-native";
import { AppTheme } from "../../App.theme";

export const styles = StyleSheet.create({
  label: {
    fontSize: 16,
    marginLeft: 8,
    marginBottom: 4,
    color: AppTheme.text,
  },
  required: {
    color: AppTheme.soldOut,
  },
});

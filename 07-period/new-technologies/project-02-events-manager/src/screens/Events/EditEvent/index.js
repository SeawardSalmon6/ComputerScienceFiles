import { useRoute } from "@react-navigation/native";
import { Layout } from "../../../components/Layout";
import { Header } from "../../../components/Header";
import { AppTextInput } from "../../../components/AppTextInput";
import { useState } from "react";
import { Alert, Image, Pressable, Text, View } from "react-native";
import { styles } from "./styles";
import DateTimePicker from "@react-native-community/datetimepicker";
import dayjs from "dayjs";
import { AppTheme } from "../../../App.theme";
import Icon from "react-native-vector-icons/Octicons";
import * as ImagePicker from "expo-image-picker";
import { Label } from "../../../components/Label";
import { EventCard } from "../../../components/EventCard";
import { useEventsContext } from "../../../contexts/Events/useEventsContext";
import { AnimatedButton } from "../../../components/AnimatedButton";
import { useAppNavigation } from "../../../hooks/useAppNavigation";
import { isEventPayloadValid } from "../../../contexts/Events/constants";

export function EditEvent() {
  const { params } = useRoute();
  const [event, setEvent] = useState((params && params.event) ?? {});
  const [showDatePicker, setShowDatePicker] = useState(false);
  const [showTimePicker, setShowTimePicker] = useState(false);
  const { eventsDispatcher } = useEventsContext();
  const { goTo } = useAppNavigation();
  const isCreateAction = !event || !event.id;

  const updateEventProperty = (key, value) => {
    setEvent((prev) => ({ ...prev, [key]: value }));
  };

  const getOnChange = (key) => (value) => {
    updateEventProperty(key, value);
  };

  const openPicker = (picker = "date") => {
    if (picker === "date") {
      setShowDatePicker(true);
    } else {
      setShowTimePicker(true);
    }
  };

  const closePicker = (picker = "date") => {
    if (picker === "date") {
      setShowDatePicker(false);
    } else {
      setShowTimePicker(false);
    }
  };

  const pickImage = async () => {
    const result = await ImagePicker.launchImageLibraryAsync({
      mediaTypes: ImagePicker.MediaTypeOptions.Images,
      base64: true,
      allowsEditing: true,
      quality: 1,
      allowsMultipleSelection: false,
      selectionLimit: 1,
    });

    if (!result.canceled) {
      updateEventProperty(
        "image",
        "data:image/jpeg;base64," + result.assets[0].base64
      );
    }
  };

  return (
    <Layout>
      <Layout.Header
        title={isCreateAction ? "Criar Evento" : "Editar Evento"}
        backTo="EventsScreen"
      />
      <Layout.Content>
        <Header level="h2">Sobre o evento</Header>
        <View style={styles.inputContainer}>
          <AppTextInput
            label="Nome do evento"
            textInputProps={{ placeholder: "Ex.: Meu evento maneiro" }}
            onChange={getOnChange("title")}
            required
            value={event.title}
          />
          <AppTextInput
            label="Descrição"
            onChange={getOnChange("description")}
            required
            textInputProps={{
              placeholder: "Ex.: Meu evento é maneiro e é isso",
              multiline: true,
              numberOfLines: 8,
            }}
            textarea
            style={styles.textarea}
            value={event.description}
          />
          <AppTextInput
            label="Localização"
            textInputProps={{
              placeholder: "Ex.: Rua Maneira dos Canaviais Maneiros, nº 78",
            }}
            onChange={getOnChange("location")}
            required
            value={event.location}
          />
          <View style={styles.uploadContainer}>
            <Label label="Imagem do Evento" required />
            <Pressable onPress={pickImage}>
              {event.image ? (
                <Image
                  source={{ uri: event.image }}
                  style={styles.image}
                  resizeMode="cover"
                />
              ) : (
                <EventCard.Empty text={"Clique aqui para alterar a imagem"} />
              )}
            </Pressable>
          </View>
        </View>
        <Header containerStyle={styles.titleContainer} level="h2">
          Hora e data
        </Header>
        <View style={styles.inputContainer}>
          <AppTextInput
            label="Data do evento"
            textInputProps={{
              placeholder: "Ex.: DD/MM/YYYY",
              readOnly: true,
            }}
            onPress={() => {
              openPicker();
            }}
            required
            value={event.date ? dayjs(event.date).format("DD/MM/YYYY") : ""}
            suffix={
              <Icon name="calendar" size={18} color={AppTheme.placeholder} />
            }
          />
          {showDatePicker && (
            <DateTimePicker
              themeVariant="dark"
              accentColor={AppTheme.accent}
              textColor={AppTheme.text}
              mode="date"
              onChange={(_, date) => {
                closePicker();

                if (date) {
                  updateEventProperty("date", dayjs(date).format("YYYY-MM-DD"));
                }
              }}
              minimumDate={dayjs().toDate()}
              value={dayjs(event.date).toDate()}
            />
          )}
          <AppTextInput
            label="Horário do evento"
            textInputProps={{
              placeholder: "Ex.: HH:mm",
              readOnly: true,
            }}
            onPress={() => {
              openPicker("time");
            }}
            required
            value={event.time}
            suffix={
              <Icon name="clock" size={18} color={AppTheme.placeholder} />
            }
          />
          {showTimePicker && (
            <DateTimePicker
              themeVariant="dark"
              accentColor={AppTheme.accent}
              mode="time"
              is24Hour
              onChange={(_, date) => {
                closePicker("time");

                if (date) {
                  updateEventProperty("time", dayjs(date).format("HH:mm"));
                }
              }}
              minimumDate={dayjs().toDate()}
              value={
                dayjs(event.time, "HH:mm").isValid()
                  ? dayjs(event.time, "HH:mm").toDate()
                  : dayjs().toDate()
              }
            />
          )}
        </View>
        <Header containerStyle={styles.titleContainer} level="h2">
          Ingressos
        </Header>
        <View style={styles.inputContainer}>
          <AppTextInput
            label="Preço do ingresso"
            textInputProps={{
              placeholder: "Ex.: R$ 10,00",
              keyboardType: "numeric",
              separator: ",",
              precision: 2,
              prefix: "R$ ",
            }}
            type="numeric"
            required
            onChange={(value) => {
              updateEventProperty("price", parseFloat(value));
            }}
            value={event.price}
          />
          <AppTextInput
            label="Ingressos disponíveis"
            required
            textInputProps={{
              placeholder: "Ex.: 100",
              keyboardType: "numeric",
              precision: 0,
              separator: ",",
            }}
            type="numeric"
            onChange={(value) => {
              updateEventProperty("available", parseInt(value, 10));
            }}
            value={event.available}
          />
        </View>
        <View style={styles.buttonContainer}>
          <AnimatedButton
            onPress={() => {
              if (!isEventPayloadValid(event)) {
                Alert.alert(
                  "Dados inválidos",
                  "Por favor, preencha todos os campos obrigatórios"
                );
                return;
              }

              eventsDispatcher({
                type: isCreateAction ? "create" : "update",
                payload: event,
              });

              Alert.alert("Evento salvo", "Seu evento foi salvo com sucesso!");
              goTo("EventsScreen");
            }}
            style={styles.button}
          >
            <Text style={styles.buttonText}>Salvar</Text>
          </AnimatedButton>
        </View>
      </Layout.Content>
    </Layout>
  );
}
